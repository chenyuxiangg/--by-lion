/*
��������̣�
---- 1�� ������������Ĵ�����ϢΪ��

Tray Bar�Ĵ��������ǣ�Shell_TrayWnd

��ʼ��ť�Ĵ��������ǣ�Button

Ӧ�ó����л����Ĵ��������ǣ�ReBarWindow32

������֪ͨ���Ĵ��������ǣ�TrayNotifyWnd

������ʱ�ӵĴ��������ǣ�TrayClockWClass
*/

//#include <windows.h>
//#include <windowsx.h>
//#include <CommCtrl.h>
//#include <iostream>
//#include <COMMCTRL.H>
//using namespace std;
//
//int main(int argc, char* argv[]) {
//	//��������ΪCabinetWClass,������ΪBaiduNetdiskDownload�Ĵ���
//	HWND shell_hwnd = ::FindWindowEx(0, 0, TEXT("Shell_TrayWnd"),0);
//	if (shell_hwnd) {
//		HWND bar_hwnd = ::FindWindowEx(shell_hwnd, 0, TEXT("ReBarWindow32"), 0);
//		if (bar_hwnd) {
//			HWND hwnd = ::FindWindowEx(bar_hwnd, 0, TEXT("MSTaskSwWClass"), TEXT("�����е�Ӧ�ó���"));
//			if (hwnd) {
//				//����͸������������������е�Ԫ�ض�͸��
//				LONG exstyle = ::GetWindowLong(hwnd, GWL_EXSTYLE);
//				exstyle |= WS_EX_LAYERED;
//				::SetWindowLong(hwnd, GWL_EXSTYLE, exstyle);
//				::SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);
//				cout << "Ŀ�괰��������Ϊ��͸����" << endl;
//			}
//			else
//				cout << "��ȡĿ��ʧ�ܣ�" << endl;
//		}
//		else
//			cout << "��ȡReBarWindow32����ʧ�ܣ�" << endl;
//	}
//	else
//		cout << "��ȡshell����ʧ�ܣ�" << endl;
//	system("pause");
//	return 0;
//}

//��ȡӦ�ó�������·��(���ɿ�ݷ�ʽֱ�ӻ�ȡ������·��)
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
		//�ѵ�һ���ļ���ǰ�ĸ��Ƶ�szPath,��:
		//���ֻѡ��һ���ļ�,�͸��Ƶ����һ��'\'
		//���ѡ�˶���ļ�,�͸��Ƶ���һ��NULL�ַ�
		lstrcpyn(szPath, szOpenFileNames, ofn.nFileOffset);
		//��ֻѡ��һ���ļ�ʱ,�������NULL�ַ��Ǳ����.
		//���ﲻ����Դ�ѡ��һ���Ͷ���ļ������
		szPath[ofn.nFileOffset] = '\0';
		nLen = lstrlen(szPath);

		if (szPath[nLen - 1] != '\\')   //���ѡ�˶���ļ�,��������'\\'
		{
			lstrcat(szPath, TEXT("\\"));
		}

		p = szOpenFileNames + ofn.nFileOffset; //��ָ���Ƶ���һ���ļ�

		ZeroMemory(szFileName, sizeof(szFileName));
		while (*p)
		{
			lstrcat(szFileName, szPath);  //���ļ�������·��  
			lstrcat(szFileName, p);    //�����ļ���  
			lstrcat(szFileName, TEXT("\n")); //����   
			p += lstrlen(p) + 1;     //������һ���ļ�
		}
		MessageBox(NULL, szFileName, TEXT("MultiSelect"), MB_OK);
	}
	system("pause");
	return 0;
}