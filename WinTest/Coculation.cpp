#include "Coculation.h"
//定义一些全局变量
string gsname;
char* cerror;
char* pcurrent;
double gdnumber;
FLAG gFflag;
map<string, double> gtable;

FLAG Ggetvalue(char* &pch)
{
	if (!pch)
		return gFflag = END;

	switch (*pch)
	{
	case '+':case '-':case '*':case '/':
	case '=':case '(':case ')':case ';':
	{
		gFflag = FLAG(*pch);
		++pch;
		return gFflag;
	}

	case '0':case '1':case '2':case '3':
	case '4':case '5':case '6':case '7':
	case '8':case '9':case '.':
	{
		char tmp[20];
		tmp[0] = *pch;
		++pch;
		int i = 0;
		while ((*pch > '0' && *pch < '9') || *pch == '.')
		{
			tmp[++i] = *pch;
			++pch;
		}
		tmp[++i] = '\0';
		gdnumber = atof(tmp);
		return gFflag = NUMBER;
	}

	default:
	{
		if (isalpha(*pch))
		{
			char tmp[20];
			tmp[0] = *pch;
			++pch;
			int i = 0;

			while (isalpha(*pch))
			{
				tmp[++i] = *pch;
				++pch;
			}
			tmp[++i] = '\0';
			gsname = tmp;
			return gFflag = NAME;
		}
		cerror = "表达式错误";
		return gFflag = MERROR;
	}

	}
}

double Gexpr(bool bget)
{
	double tleft = Gterm(bget);
	while (true)
	{
		switch (gFflag)
		{
		case '+':
		{
			tleft += Gterm(true);
			break; 
		}
		case '-':
		{
			tleft -= Gterm(true);
			break;
		}
		default:return tleft;
		}
	}
}

double Gterm(bool bget)
{
	double tleft = Gprim(bget);
	while (true)
	{
		switch (gFflag)
		{
		case '*':
		{
			tleft *= Gprim(true);
			break;
		}
		case '/':
		{
			tleft /= Gprim(true);
			break;
		}
		default:return tleft;
		}
	}
}

double Gprim(bool bget)
{
	double e = 0;
	if (bget)
		Ggetvalue(pcurrent);

	switch (gFflag)
	{
	case NUMBER:
	{
		e = gdnumber;
		Ggetvalue(pcurrent);
		return e;
	}

	case NAME:
	{
		double& v = gtable[gsname];
		if (Ggetvalue(pcurrent) == EQUL)
			v = Gexpr(true);
		return v;
	}

	case MLP:
	{
		e = Gexpr(true);
		if (gFflag != MRP)
		{
			cerror = "缺少右括号";
			gFflag = MERROR;
			return e;
		}
		Ggetvalue(pcurrent);
		return e;
	}

	case MUN:
	{
		e = -Gprim(true);
		return e;
	}
	case ADD:
	{
		e = Gprim(true);
		return e;
	}

	default:
	{
		cerror = "表达式错误";
		return e;
	}
	}
}