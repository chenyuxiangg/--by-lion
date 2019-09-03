/*
任务栏编程：
---- 1、 任务栏各窗体的窗口信息为：

Tray Bar的窗口类名是：Shell_TrayWnd

开始按钮的窗口类名是：Button

应用程序切换区的窗口类名是：ReBarWindow32

任务栏通知区的窗口类名是：TrayNotifyWnd

任务栏时钟的窗口类名是：TrayClockWClass
*/

//#include <windows.h>
//#include <windowsx.h>
//#include <CommCtrl.h>
//#include <iostream>
//#include <COMMCTRL.H>
//using namespace std;
//
//int main(int argc, char* argv[]) {
//	//查找类名为CabinetWClass,窗口名为BaiduNetdiskDownload的窗口
//	HWND shell_hwnd = ::FindWindowEx(0, 0, TEXT("Shell_TrayWnd"),0);
//	if (shell_hwnd) {
//		HWND bar_hwnd = ::FindWindowEx(shell_hwnd, 0, TEXT("ReBarWindow32"), 0);
//		if (bar_hwnd) {
//			HWND hwnd = ::FindWindowEx(bar_hwnd, 0, TEXT("MSTaskSwWClass"), TEXT("运行中的应用程序"));
//			if (hwnd) {
//				//设置透明，但会把整个窗口中的元素都透明
//				LONG exstyle = ::GetWindowLong(hwnd, GWL_EXSTYLE);
//				exstyle |= WS_EX_LAYERED;
//				::SetWindowLong(hwnd, GWL_EXSTYLE, exstyle);
//				::SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);
//				cout << "目标窗口已设置为半透明！" << endl;
//			}
//			else
//				cout << "获取目标失败！" << endl;
//		}
//		else
//			cout << "获取ReBarWindow32窗口失败！" << endl;
//	}
//	else
//		cout << "获取shell窗口失败！" << endl;
//	system("pause");
//	return 0;
//}

//获取应用程序所在路径(可由快捷方式直接获取到程序路径)
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	OPENFILENAME ofn;
	TCHAR szOpenFileNames[80 * MAX_PATH];
	TCHAR szPath[MAX_PATH];
	TCHAR szFileName[80 * MAX_PATH];
	TCHAR* p;
	int nLen = 0;
	ZeroMemory(&ofn, sizeof(ofn));
	
	ofn.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT;
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szOpenFileNames;
	ofn.nMaxFile = sizeof(szOpenFileNames);
	ofn.lpstrFile[0] = '\0';
	ofn.lpstrFilter = TEXT("exect(*.exe)\0*.EXE\0");
	if (GetOpenFileName(&ofn))
	{
		//把第一个文件名前的复制到szPath,即:
		//如果只选了一个文件,就复制到最后一个'\'
		//如果选了多个文件,就复制到第一个NULL字符
		lstrcpyn(szPath, szOpenFileNames, ofn.nFileOffset);
		//当只选了一个文件时,下面这个NULL字符是必需的.
		//这里不区别对待选了一个和多个文件的情况
		szPath[ofn.nFileOffset] = '\0';
		nLen = lstrlen(szPath);

		if (szPath[nLen - 1] != '\\')   //如果选了多个文件,则必须加上'\\'
		{
			lstrcat(szPath, TEXT("\\"));
		}

		p = szOpenFileNames + ofn.nFileOffset; //把指针移到第一个文件

		ZeroMemory(szFileName, sizeof(szFileName));
		while (*p)
		{
			lstrcat(szFileName, szPath);  //给文件名加上路径  
			lstrcat(szFileName, p);    //加上文件名  
			lstrcat(szFileName, TEXT("\n")); //换行   
			p += lstrlen(p) + 1;     //移至下一个文件
		}
		MessageBox(NULL, szFileName, TEXT("MultiSelect"), MB_OK);
	}
	system("pause");
	return 0;
}