#include "CYufa.h"
#include <cmath>
#include <iostream>
using namespace std;

extern Token tokentable[];

CYufa::CYufa(){
	m_lexical = new Clexical_Analyzer();
}

CYufa::~CYufa(){
	delete m_lexical;
	m_lexical = NULL;
	double Parameter = 0;
}

//分析一句话 
void CYufa::Parser(char* srcFileptr){
	m_lexical->Analyze(srcFileptr);
	FetchToken();
	Program();
	m_lexical->Clear(); 
}

void CYufa::FetchToken(){
	m_token = m_lexical->GetToken();
}

void CYufa::Program(){
	while(m_token.type != TNULL){
		Statement();
		MatchToken(SEMICO);
	}
	cout << "语法分析成功" << endl; 
}

void CYufa::Statement(){
	switch(m_token.type){
		case FOR:
			ForStatement();
			break;
		case ORIGIN:
			OriginStatement();
			break;
		case ROT:
			RotStatement();
			break;
		case SCALE:
			ScaleStatement();
			break;
		default:
			cout << "statement:";
			SyntaxError(m_lexical->GetCount());
			break;
	}
}

void CYufa::ForStatement(){
	cout << "进入For语句" << endl;
	ExprNode* start_ptr = NULL;
	ExprNode* end_ptr = NULL;
	ExprNode* step_ptr = NULL;
	ExprNode* x_ptr = NULL;
	ExprNode* y_ptr = NULL;
	
	FetchToken();
	MatchToken(T);
	MatchToken(FROM);		start_ptr = Expression(); 
	MatchToken(TO);			end_ptr = Expression(); PrintSyntaxTree(end_ptr,0);
	MatchToken(STEP);		step_ptr = Expression(); 
	MatchToken(DRAW);
	MatchToken(L_BRACKET);	x_ptr = Expression(); 
	MatchToken(COMMA);		y_ptr = Expression(); 
	MatchToken(R_BRACKET); 
} 

void CYufa::OriginStatement(){
	cout << "进入OriginStatement" << endl;
	ExprNode* x_ptr = NULL;
	ExprNode* y_ptr = NULL;
	
	FetchToken();
	MatchToken(IS);
	MatchToken(L_BRACKET);	x_ptr = Expression();
	MatchToken(COMMA);		y_ptr = Expression();
	MatchToken(R_BRACKET);
}

void CYufa::ScaleStatement(){
	cout << "进入ScaleStatement" << endl;
	ExprNode* x_ptr = NULL;
	ExprNode* y_ptr = NULL;
	
	FetchToken();
	MatchToken(IS);
	MatchToken(L_BRACKET);	x_ptr = Expression();
	MatchToken(COMMA);		y_ptr = Expression();
	MatchToken(R_BRACKET);
}

void CYufa::RotStatement(){
	cout << "进入RotStatement" << endl;
	ExprNode* rot_ptr = NULL;

	FetchToken();
	MatchToken(IS);			rot_ptr = Expression();
}

void  CYufa::MatchToken(Token_type token_t){
	if(token_t != m_token.type){
		cout << "matchToken:";
		SyntaxError(m_lexical->GetCount());
	}
	FetchToken();
}

ExprNode* CYufa::Expression(){
	ExprNode* left = NULL;
	ExprNode* right = NULL;
	Token_type token_tmp;
	left = Term();
	while(m_token.type == PLUS || m_token.type == MINUS){
		token_tmp = m_token.type;
		MatchToken(token_tmp);
		right = Term();
		left = MakeExprNode(token_tmp,left,right);
	} 
	return left;
}

ExprNode* CYufa::MakeExprNode(Token_type opcode,...){
	ExprNode* ExprPtr = new ExprNode();
	va_list ArgPtr;
	ExprPtr->OpCode = opcode;
	va_start(ArgPtr,opcode);
	switch(opcode){
		case CONST_ID:
			ExprPtr->Content.CaseConst = (double)va_arg(ArgPtr,double);
			break;
		case T:
			ExprPtr->Content.CaseParmPtr = &Parameter;
			break;
		case FUNC:
			ExprPtr->Content.CaseFunc.Child = (ExprNode*)va_arg(ArgPtr,ExprNode*);
			ExprPtr->Content.CaseFunc.MathFuncPtr = (FuncPtr)va_arg(ArgPtr,FuncPtr);
			break;
		default:
			ExprPtr->Content.CaseOperator.left = (ExprNode*)va_arg(ArgPtr,ExprNode*);
			ExprPtr->Content.CaseOperator.right = (ExprNode*)va_arg(ArgPtr,ExprNode*);
			break;
	}
	va_end(ArgPtr);
	return ExprPtr;
}

void CYufa::SyntaxError(int errornu){
	cout << "error position:" << errornu << endl;
}

ExprNode* CYufa::Term(){
	ExprNode* left = NULL;
	ExprNode* right = NULL;
	Token_type token_tmp;
	left = Factor();
	while(m_token.type == MUL || m_token.type == DIV){
		token_tmp = m_token.type;
		MatchToken(token_tmp);
		right = Factor();
		left = MakeExprNode(token_tmp,left,right);
	}
	return left;
}

ExprNode* CYufa::Factor(){
	ExprNode* left = NULL;
	ExprNode* right = NULL;
	Token_type token_tmp;
	if(m_token.type == PLUS || m_token.type == MINUS){
		left = MakeExprNode(CONST_ID,0.0);
		token_tmp = m_token.type;
		MatchToken(token_tmp);
		right = Factor();
		left = MakeExprNode(token_tmp,left,right);
		return left;
	}
	else{
		left = Component();
	}
	return left;
}

ExprNode* CYufa::Component(){
	ExprNode* left = NULL;
	left = Atom();
	if(m_token.type == POWER){
		Token_type token_tmp = m_token.type;
		MatchToken(token_tmp);
		ExprNode* right = Component();
		left = MakeExprNode(token_tmp,left,right);
	}
	return left;
}

ExprNode* CYufa::Atom(){
	ExprNode* ret = NULL;
	Token_type token_tmp = m_token.type;
	Token tmp = m_token;
	MatchToken(token_tmp);
	switch(token_tmp){
		case CONST_ID:
			return MakeExprNode(token_tmp,tmp.value);
		case T:
			return MakeExprNode(token_tmp,tmp.value);
		case FUNC:
			MatchToken(L_BRACKET);
			ret = Expression();
			MatchToken(R_BRACKET); 
			return MakeExprNode(token_tmp,ret,tmp.FuncPtr);
		case L_BRACKET: 
			ret = Expression();
			MatchToken(R_BRACKET);
			return ret;
		default:
			cout << "atom:";
			SyntaxError(m_lexical->GetCount());
			cout << ",error type:" << token_tmp << endl;
			return NULL;
	}
}

void CYufa::PrintSyntaxTree(ExprNode* root,int indent){
	switch(root->OpCode){
		case CONST_ID:
			for(int i = 0 ;i < indent;++i){
				cout << " ";
			} 
			cout << root->Content.CaseConst << endl;
			break;
		case T:
			for(int i = 0;i < indent;++i){
				cout << " ";
			}
			cout << "T" << endl;
		case FUNC:
			for(int i = 0;i < indent;++i){
				cout << " ";
			}
			for(int i = 0;i < 18;++i){
				if(root->Content.CaseFunc.MathFuncPtr == tokentable[i].FuncPtr)
				{
					cout << tokentable[i].lexeme << endl;
					break;
				}
			}
			PrintSyntaxTree(root->Content.CaseFunc.Child,indent+2);
			break;
		default:
			for(int i = 0;i < indent;++i){
				cout << " ";
			}
			switch(root->OpCode){
				case PLUS:
					cout << "+" << endl;
					break;
				case MINUS:
					cout << "-" << endl;
					break;
				case MUL:
					cout << "*" << endl;
					break;
				case DIV:
					cout << "/" << endl;
					break;
				case POWER:
					cout << "**" << endl;
					break; 
				default:
					return;
			}
			PrintSyntaxTree(root->Content.CaseOperator.left,indent+2);
			PrintSyntaxTree(root->Content.CaseOperator.right,indent+2);
			break;
	}
}


