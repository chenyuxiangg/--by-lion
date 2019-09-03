#include "MY.h"

static char szcobject[] = "cobject";
struct CruntimeClass cobject::classcobject = { szcobject,sizeof(cobject),0xFFFF,NULL,NULL,NULL };
static afx_Classinit _init_cobject(&cobject::classcobject);

CruntimeClass* CruntimeClass::pFirstClass = NULL;

afx_Classinit::afx_Classinit(CruntimeClass* pNewClass)
{
	pNewClass->m_pNextClass = CruntimeClass::pFirstClass;
	CruntimeClass::pFirstClass = pNewClass;
}

CruntimeClass* cobject::Getruntimeclass() const {
	return &cobject::classcobject;
}

BOOL cwnd::mcreate() {
	return TRUE;
}

BOOL cwnd::mcreateEx() {
	precreatewindow();
	return TRUE;
}

BOOL cwnd::precreatewindow() {
	return TRUE;
}

BOOL cframewnd::precreatewindow() {
	return TRUE;
}

BOOL cobject::iskindof(CruntimeClass* pclass) const {
	CruntimeClass* pclassthis = Getruntimeclass();
	while (pclassthis != NULL)
	{
		if (pclassthis == pclass)
		{
			return TRUE;
		}
		pclassthis = pclassthis->m_pBaseClass;
	}
	return FALSE;
}

CIMPLEMENT_DYNAMIC(ccmdtarget, cobject)
CIMPLEMENT_DYNAMIC(cwinthread,ccmdtarget)
CIMPLEMENT_DYNAMIC(cwinapp,cwinthread)
CIMPLEMENT_DYNAMIC(cwnd,ccmdtarget)
CIMPLEMENT_DYNAMIC(cframewnd,cwnd)
CIMPLEMENT_DYNAMIC(cdocument,ccmdtarget)
CIMPLEMENT_DYNAMIC(cview,cwnd)


extern cmywinapp theapp;
cwinapp* afxgetapp()
{
	return theapp.m_pcurrentwinapp;
}