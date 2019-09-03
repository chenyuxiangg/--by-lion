#include "module.h"

CModule::CModule(UINT bcount, UINT ecount) :Bcount(bcount), Ecount(ecount) {}

BOOL CModule::MyCreateBotton(HWND hwnd,HINSTANCE hInstance, BSTRUCTARR barr, WPARAM wParam, LPARAM lParam)
{
	if (!BottonArr.empty())
	{
		BottonArr.clear();
	}
	for (size_t i = 0; i < Bcount; ++i)
	{
		HWND hbutton = NULL;
		if (!(hbutton = CreateWindow(TEXT("Button"), barr[i].identy, BUTTONSTALY, barr[i].x, barr[i].y, barr[i].wedth, barr[i].height, hwnd, NULL, hInstance, NULL)))
		{
			MessageBox(NULL, TEXT("°´Å¥´´½¨Ê§°Ü£¡"), TEXT("error"), MB_OK);
			return FALSE;
		}
		BottonArr.push_back(hbutton);
	}
	return TRUE;
}

BOOL CModule::MyCreateEdit(HWND hwnd, HINSTANCE hInstance, ESTRUCTARR earr, WPARAM wParam, LPARAM lParam, DWORD dStaly)
{
	if (!EditArr.empty())
	{
		EditArr.clear();
	}
	for (size_t i = 0; i < Ecount; ++i)
	{
		HWND hedit = NULL;
		if (!(hedit = CreateWindow(_TEXT("Edit"), earr[i].identy, EDITSTALY | dStaly, earr[i].x, earr[i].y, earr[i].wedth, earr[i].height, hwnd, NULL, hInstance, NULL)))
		{
			MessageBox(NULL, _TEXT("´´½¨ÎÄ±¾±à¼­¿òÊ§°Ü£¡"), _TEXT("error"), MB_OK);
			return FALSE;
		}
		EditArr.push_back(hedit);
	}
	return TRUE;
}

BOOL CModule::MyDestory()
{
	for (std::vector<HWND>::iterator it = BottonArr.begin(); it != BottonArr.end(); ++it)
	{
		if (*it && !DestroyWindow(*it))
		{
			MessageBox(NULL, TEXT("error"), TEXT("Ïú»Ù°´Å¥Ê§°Ü£¡"),MB_OK);
			return FALSE;
		}
		*it = NULL;
	}
	for (std::vector<HWND>::iterator it = EditArr.begin(); it != EditArr.end(); ++it)
	{
		if (*it && !DestroyWindow(*it))
		{
			MessageBox(NULL, TEXT("error"), TEXT("Ïú»ÙÎÄ±¾¿òÊ§°Ü£¡"),MB_OK);
			return FALSE;
		}
		*it = NULL;
	}
	return TRUE;
}

UINT CModule::MyGetconect(HWND hwnd, _TCHAR* content)
{
	UINT ilength = SendMessage(hwnd, EM_GETLINE, 0, (LPARAM)content);
	return ilength;
}

HWND CModule::MyGetBA(int i)
{
	return BottonArr[i];
}

HWND CModule::MyGetEA(int i)
{
	return EditArr[i];
}

UINT CModule::MyGetBcount() const
{
	return Bcount;
}

UINT CModule::MyGetEcount() const
{
	return Ecount;
}