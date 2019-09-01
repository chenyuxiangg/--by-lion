#ifndef STRUCT_H
#define STRUCT_H

typedef double(*FuncPtr)(double);
class ExprNode{
	public:
		Token_type OpCode;		//记号种类
		union{
			typedef struct{
				ExprNode* left;
				ExprNode* right;
			}CaseOperator;
		
			typedef struct{
				ExprNode* Child;
				FuncPtr MathFuncPtr;
			}CaseFunc;
		
			double CaseConst;			//常数，绑定右值 
			double* CaseParmPtr;		//参数T,绑定左值 
		}Content; 
		
};

#endif
