#include <windows.h>
#include <stdio.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <tchar.h>
#include "resource.h"
#include "Coculation.h"

//lib
#pragma comment(lib,"winmm.lib")

//macro
#define KEY_DOWN(vk) (GetAsyncKeyState(vk) & 0x8000 ? 1 : 0)
#define WIN32_LEAN_AND_MEAN
#define CLASS_NAME TEXT("MYCLASS")
#define WINDOW_TITLE TEXT("MYWINDOW")
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define ID_EDIT 1

//��������
extern map<string, double> gtable; 
extern char* pcurrent;
extern FLAG gFflag;
extern char* cerror;

//global
HINSTANCE My_hIstance = NULL;
HWND hEdit = NULL;
RECT rshow;

//WinProc
LRESULT CALLBACK MyWinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

VOID Coculate(HWND fhwnd,HWND hwnd, HDC hdc);

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//Rect
	rshow.top = 150;
	rshow.bottom = 170;
	rshow.left = 300;
	rshow.right = 400;

	//WindowClass
	WNDCLASSEX WindowClass;

	WindowClass.cbSize = sizeof(WNDCLASSEX);
	WindowClass.hInstance = hInstance;
	WindowClass.lpfnWndProc = MyWinProc;
	WindowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WindowClass.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));
	WindowClass.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS | CS_OWNDC;
	WindowClass.hIconSm = NULL;//LoadIcon(hInstance,ICON_ID1);//Сͼ�����ȼ��Ǵ���hIcon�ģ���Сͼ������ΪĬ��ͼ��ʱ��hIcon���ó�ʲôͼƬͼ�궼����ı�
	WindowClass.cbClsExtra = 0;
	WindowClass.cbWndExtra = 0;
	WindowClass.lpszClassName = CLASS_NAME;
	WindowClass.lpszMenuName = MAKEINTRESOURCE(MY_MENU);

	//register
	if (!RegisterClassEx(&WindowClass))
		return (0);
	My_hIstance = hInstance;

	//create
	HWND hwnd;
	MSG msg;

	if (!(hwnd = CreateWindow(CLASS_NAME, WINDOW_TITLE, WS_OVERLAPPEDWINDOW, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL)))
		return (0);

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	//message loop
	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}
	return (msg.wParam);//Why???
}

LRESULT CALLBACK MyWinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	static HWND hwndEdit;

	switch (msg)
	{
	case WM_CREATE:
	{
		PlaySound(MAKEINTRESOURCE(SOUND_ID_CREATE), My_hIstance, SND_ASYNC | SND_RESOURCE);//��֣�Ϊʲô����Դ���������Ͳ���
		
		hwndEdit = CreateWindow(TEXT("Edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER
		, 300, 100, 100,20, hwnd, (HMENU)ID_EDIT, My_hIstance, NULL);//ES_MULTILINE ��� ES_HSCORLL ES_VSCROLL �Լ��������Զ��ı�һ��ʹ��
		hEdit = hwndEdit;
		return (0);
	}
	break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd,&ps);

		//����ַ������룺��
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, 250, 100, TEXT("���룺"), _tcslen(TEXT("���룺")));

		//����ַ����������
		TextOut(hdc, 250, 150, TEXT("�����"), _tcslen(TEXT("�����")));

		//�����
		Rectangle(hdc, rshow.left, rshow.top, rshow.right, rshow.bottom);

		EndPaint(hwnd, &ps);
		return (0);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case MENU_HELP_ID_ABOUT:
		{
			MessageBox(hwnd, TEXT("Hello,World! --Versoin 1.0"), TEXT("About"), MB_OK);
			return (0);
		}
		break;

		case MENU_FILE_ID_EXIT:
		{
			PostQuitMessage(0);
			return (0);
		}
		break;

		default:break;
		}

		switch (HIWORD(wParam))
		{
		case EN_UPDATE:
		{
			if (KEY_DOWN(VK_SPACE))
			{
				HDC hdc = GetDC(hwnd);

				Coculate(hwnd, hEdit, hdc);

				ReleaseDC(hwnd, hdc);
			}
			return (0);
		}
		break;

		default: break;
		}
	}
	break;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
		{
			PostQuitMessage(0);
			return (0);
		}break;

		default:break;

		}
	}

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return (0);
	}
	break;

	default:break;
	}

	return (DefWindowProc(hwnd, msg, wParam, lParam));
}

VOID Coculate(HWND fhwnd,HWND chwnd, HDC hdc)
{
	//���ű�ֵ
	gtable["pi"] = 3.1415926;
	gtable["e"] = 2.7182818;
	//�ӱ༭�ؼ���ȡһ��
	char ctransform[80];
	char myresult[20];
	TCHAR tmpbuf[80] = TEXT(" ");//������ֵ����������쳣
	size_t ilength = SendMessage(hEdit, EM_GETLINE, 0, (LPARAM)tmpbuf);

	//����
	WideCharToMultiByte(CP_ACP, 0, tmpbuf, _tcslen(tmpbuf)+1, ctransform, sizeof(ctransform), 0, FALSE);
	pcurrent = ctransform;
	Ggetvalue(pcurrent);
	if (gFflag == END)
		return;
	while (gFflag == PRINT)
	{
		Ggetvalue(pcurrent);
	}
	double res = Gexpr(false);
	if (gFflag == MERROR)
	{
		MultiByteToWideChar(CP_ACP, 0, cerror, strlen(cerror) + 1, tmpbuf, _tcslen(tmpbuf));
	}
	else
	{
		sprintf_s(myresult, "%lf", res);
		MultiByteToWideChar(CP_ACP, 0, myresult, strlen(myresult) + 1, tmpbuf, _tcslen(tmpbuf));
	}
	//��ʾ����Ļ
	//ˢ�¾�������
	Rectangle(hdc, rshow.left, rshow.top, rshow.right, rshow.bottom);

	if (ilength)
	{
		DrawText(hdc, tmpbuf, -1, &rshow, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	return;
}