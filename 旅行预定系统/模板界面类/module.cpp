#include "module.h"

_TCHAR wBnotation[21][9] = {
	TEXT("Button1"),TEXT("Button2"),TEXT("Button3"),TEXT("Button4")
	,TEXT("Button5"),TEXT("Button6"),TEXT("Button7"),TEXT("Button8")
	,TEXT("Button9"),TEXT("Button10"),TEXT("Button11"),TEXT("Button12")
	,TEXT("Button13"),TEXT("Button14"),TEXT("Button15"),TEXT("Button16")
	,TEXT("Button17"),TEXT("Button18"),TEXT("Button19"),TEXT("Button20")
};

_TCHAR wEnotation[21][7] = {
	TEXT("Edit1"),TEXT("Edit2"),TEXT("Edit3"),TEXT("Edit4")
	,TEXT("Edit5"),TEXT("Edit6"),TEXT("Edit7"),TEXT("Edit8")
	,TEXT("Edit9"),TEXT("Edit10"),TEXT("Edit11"),TEXT("Edit12")
	,TEXT("Edit13"),TEXT("Edit14"),TEXT("Edit15"),TEXT("Edit16")
	,TEXT("Edit17"),TEXT("Edit18"),TEXT("Edit19"),TEXT("Edit20")
};

CModule::CModule(UINT bcount, UINT ecount) :Bcount(bcount), Ecount(ecount) {}

BOOL CModule::MyCreateBotton(HWND hwnd,HINSTANCE hInstance, BSTRUCTARR barr, WPARAM wParam, LPARAM lParam)
{
	for (size_t i = 0; i < Bcount; ++i)
	{
		HWND hwnd = NULL;
		if (!(hwnd = CreateWindow(TEXT("button"), wBnotation[i], BUTTONSTALY, barr[i].x, barr[i].y, barr[i].wedth, barr[i].height, hwnd, NULL, hInstance, NULL)))
		{
			MessageBox(NULL, TEXT("error"), TEXT("°´Å¥´´½¨Ê§°Ü£¡"), MB_OK);
			return FALSE;
		}
		BottonArr.push_back(hwnd);
	}
	return TRUE;
}

BOOL CModule::MyCreateEdit(HWND hwnd, HINSTANCE hInstance, ESTRUCTARR earr, WPARAM wParam, LPARAM lParam, DWORD dStaly = WS_CHILD)
{
	for (size_t i = 0; i < Ecount; ++i)
	{
		HWND hwnd = NULL;
		if (!(hwnd = CreateWindow(TEXT("Edit"), wEnotation[i], EDITSTALY | dStaly, earr[i].x, earr[i].y, earr[i].wedth, earr[i].height, hwnd, NULL, hInstance, NULL)))
		{
			MessageBox(NULL, TEXT("error"), TEXT("´´½¨ÎÄ±¾±à¼­¿òÊ§°Ü£¡"), MB_OK);
			return FALSE;
		}
		EditArr.push_back(hwnd);
	}
	return TRUE;
}

BOOL CModule::MyDestory()
{
	for (std::vector<HWND>::iterator it = BottonArr.begin(); it != BottonArr.end(); ++it)
	{
		if (DestroyWindow(*it))
		{
			MessageBox(NULL, TEXT("error"), TEXT("Ïú»Ù°´Å¥Ê§°Ü£¡"),MB_OK);
			return FALSE;
		}
	}
	for (std::vector<HWND>::iterator it = EditArr.begin(); it != EditArr.end(); ++it)
	{
		if (DestroyWindow(*it))
		{
			MessageBox(NULL, TEXT("error"), TEXT("Ïú»ÙÎÄ±¾¿òÊ§°Ü£¡"),MB_OK);
			return FALSE;
		}
	}
	return TRUE;
}