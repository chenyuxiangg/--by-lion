#include "CYufa.h"
#include <iostream>
using nanespace std;

CYufa::CYufa(){
	lexical = new Lexical_analyzer();
}

CYufa::~CYufa(){
	delete lexical;
	lexical = null;
	double Parameter = 0;
}

//·ÖÎöÒ»¾ä»° 
void CYufa::Parser(char* srcFileptr){
	lexical->Analyze(srcFileptr);
	FetchToken();
	Program();
	lexical->Clear(); 
}

void CYufa::FetchToken(){
	m_token = lexical->GetToken();
}

void CYufa::Program(){
	while(m_token != TNULL){
		Statement();
		MathToken(SEMICO);
	}
}

void CYufa::Statement(){
	switch(m_token){
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
			SyntaxError(0);
			break;
	}
}

void CYufa::ForStatement(){
	ExprNode* start_ptr = NULL;
	ExprNode* end_ptr = NULL;
	ExprNode* step_ptr = NULL;
	ExprNode* x_ptr = NULL;
	ExprNode* y_ptr = NULL;
	
	MatchToken(T);
	MatchToken(FROM);		start_ptr = Expression();
	MatchToken(TO);			end_ptr = Expression();
	MatchToken(STEP);		step_ptr = Expression();
	MatchToken(DRAW);
	MatchToken(L_BRACKET);	x_ptr = Expression();
	MatchToken(COMMA);		y_ptr = Expression();
	MatchToken(R_BRACKET); 
} 

void CYufa::OriginStatement(){
	ExprNode* x_ptr = NULL;
	ExprNode* y_ptr = NULL;
	
	MatchToken(IS);
	MatchToken(L_BRACKET);	x_ptr = Expression();
	MatchToken(COMMA);		y_ptr = Expression();
	MatchToken(R_BRACKET);
}

void CYufa::ScaleStatement(){
	ExprNode* x_ptr = NULL;
	ExprNode* y_ptr = NULL;
	
	MatchToken(IS);
	MatchToken(L_BRACKET);	x_ptr = Expression();
	MatchToken(COMMA);		y_ptr = Expression();
	MatchToken(R_BRACKET);
}

void CYufa::RotStatement(){
	ExprNode* rot_ptr = NULL;
	
	MatchToken(IS);			rot_ptr = Expression();
}

void  CYufa::MatchToken(Token_type token_t){
	FetchToken();
	if(token_t != m_token.type){
		SyntaxError(0);
		return;
	}
	FetchToken();
}

ExprNode* CYufa::Expression(){
	ExprNode* left = null;
	ExprNode* right = null;
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
			ExprPtr->Content.CaseFunc.MathFuncPtr = (FuncPtr)va_arg(ArgPtr,ExprNode*);
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
	cout << "error num:" << errornu << endl;
}

ExprNode* Term(){
	ExprNode* left = null;
	ExprNode* right = null;
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
	ExprNode* left = MakeExprNode(CONST_ID,0.0);
	ExprNode* right = null;
	Token_type token_tmp;
	if(m_token.type == PLUS || m_token.type == MINUS){
		token_tmp = m_token.type;
		right = Factor();
		left = MakeExprNode(token_tmp,left,right);
	}
	else{
		return Component();
	}
	return left;
}

ExprNode* CYufa::Component(){
	ExprNode* left = null;
	left = Atom();
	if(m_token.type == POWER){
		ExprNode* right = Component();
		Token_type token_tmp = m_token.type;
		left = MakeExprNode(token_tmp,left,right);
	}
	return left;
}

ExprNode* CYufa::Atom(){
	ExprNode* ret = null;
	Token_type token_tmp = m_token.type;
	MatchToken(token_tmp);
	switch(token_tmp){
		case CONST_ID:
			return MakeExprNode(token_tmp,m_token.value);
		case T:
			return MakeExprNode(token_tmp,m_token.value);
		case FUNC:
			MatchToken(L_BRACKET);
			ret = Expression();
			MatchToken(R_BRACKET);
			return MakeExprNode(token_tmp,ret);
		case L_BRACKET: 
			ret = Expression();
			MatchToken(R_BRACKET);
			return MakeExprNode(token_tmp,ret);
		default:
			SyntaxError(0);
			return null;
	}
}


