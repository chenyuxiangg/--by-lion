#ifndef REGEX_H
#define REGEX_H

enum Token_type{
	TNULL,
	ORIGIN,SCALE,ROT,IS,//保留字 
	TO,STEP,DRAW,FOR,FROM,T,//保留字 
	SEMICO,L_BRACKET,R_BRACKET,COMMA,//分隔符 
	PLUS,MINUS,MUL,DIV,POWER,//运算符 
	FUNC,//函数 
	CONST_ID,//常数 
	NONTOKEN,//空标记 
	ERRTOKEN,//错误标记 
	COMMENT
};

typedef struct Token{
	Token_type type;
	char* lexeme;
	double value;
	double (*FuncPtr)(double);
} Token;
#endif
