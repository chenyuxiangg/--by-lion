#pragma once
#ifndef MFC_H
#define MFC_H

#include <iostream>
#include <windows.h>
using namespace std;

//2018年6月23日
class cobject;
struct CruntimeClass {
	//Attributes
	LPCSTR m_lpszClassname;
	int m_nobjectSize;
	UINT m_wSchema;
	cobject* (PASCAL* m_pfnCreateobject)();//focus on
	CruntimeClass* m_pBaseClass;
	CruntimeClass* m_pNextClass;

	//动态类型识别
	cobject* createobject();
	static CruntimeClass* PASCAL mload();

	//CruntimeClass objects linked together in simple list
	static CruntimeClass* pFirstClass;
};

//用一个结构完成链表的连接
struct afx_Classinit {
	afx_Classinit(CruntimeClass* pNewClass);//construction

};

#define CRUNTIME_CLASS(class_name) \
	(&class_name::class##class_name)

#define CDECLARE_DYNAMIC(class_name) \
public: \
	static CruntimeClass class##class_name; \
	virtual CruntimeClass* Getruntimeclass() const;

#define _CIMPLEMENT_RUNTIMECLASS(class_name,base_class_name,wSchema,pfnNew) \
	static char _lpsz##class_name[] = #class_name; \
	CruntimeClass class_name::class##class_name = { \
	_lpsz##class_name,sizeof(class_name),wSchema,pfnNew, \
	CRUNTIME_CLASS(base_class_name),NULL}; \
	static afx_Classinit _init_##class_name(&class_name::class##class_name); \
	CruntimeClass* class_name::Getruntimeclass() const \
	{return &class_name::class##class_name;}

#define CIMPLEMENT_DYNAMIC(class_name,base_class_name) \
	_CIMPLEMENT_RUNTIMECLASS(class_name,base_class_name,0xFFFF,NULL)

#define CDECLARE_DYNCREATE(class_name) \
	CDECLARE_DYNAMIC(class_name) \
	static cobject* PASCAL createobject();

#define CIMPLEMENT_DYNCREATE(class_name,base_name) \
	cobject* PASCAL class_name::createobject() \
	{return new class_name;} \
	_CIMPLEMENT_RUNTIMECLASS(class_name,base_name,0xffff,class_name::createobject)

//

class cobject {
public:
	cobject() {  }
	~cobject() {  }

	//2018年6月23日
	virtual CruntimeClass* Getruntimeclass() const;

	BOOL iskindof(CruntimeClass* pclass) const;

	static CruntimeClass classcobject;
	//
};

class ccmdtarget : public cobject {
public:
	//2018年6月23日
	//下面这条语句不能以分号结束
	CDECLARE_DYNAMIC(ccmdtarget)

	//
	ccmdtarget() {  }
	~ccmdtarget() { }
};

class cwinthread : public ccmdtarget {
public:
	//2018年6月23日
	//下面这条语句不能以分号结束
	CDECLARE_DYNAMIC(cwinthread)
	//
	cwinthread() {  }
	~cwinthread() {  }

	virtual BOOL initinstance() {
		return TRUE;
	}
	virtual int mrun() {
		return 1;
	}
};

class cwnd;
class cwinapp : public cwinthread {
public:
	//2018年6月23日
	//下面这条语句不能以分号结束
	CDECLARE_DYNAMIC(cwinapp)
	//

		cwinapp() { m_pcurrentwinapp = this; m_pmainwnd = NULL; }
	~cwinapp() {  }

	virtual BOOL initapplication()
	{
		return TRUE;
	}
	virtual BOOL initinstance() {
		return TRUE;
	}
	virtual int mrun()
	{
		return cwinthread::mrun();
	}

public:
	cwinapp* m_pcurrentwinapp;
	cwnd* m_pmainwnd;
};

class cwnd : public ccmdtarget {
public:
	//2018年6月23日
	//下面这条语句不能以分号结束
	CDECLARE_DYNAMIC(cwnd)
	//
	cwnd() {  }
	~cwnd() {  }

	virtual BOOL mcreate();
	BOOL mcreateEx();
	virtual BOOL precreatewindow();
};

class cview : public cwnd {
public:
	//2018年6月23日
	//下面这条语句不能以分号结束
	CDECLARE_DYNAMIC(cview)
	//
	cview() {  }
	~cview() {  }
};

class cframewnd : public cwnd {
public:
	//2018年6月23日
	//下面这条语句不能以分号结束
	CDECLARE_DYNAMIC(cframewnd)
	//
	cframewnd() {  }
	~cframewnd() { }

	virtual BOOL mcreate() { return TRUE; }
	virtual BOOL precreatewindow();
};

class cdocument : public ccmdtarget {
public:
	//2018年6月23日
	//下面这条语句不能以分号结束
	CDECLARE_DYNAMIC(cdocument)
	//
	cdocument() { }
	~cdocument() {  }
};

//global founction
cwinapp* afxgetapp();
#endif