#include "module.h"
#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

//�ܽᵽ WM_COMMEND ��Ϣ
//macro
#define WINDOWSCLASS_NAME _TEXT("MYCLASS")
#define WINDOWS_NAME _TEXT("���ж�Ʊϵͳ")
#define WINDOWS_WIDTH 600
#define WINDOWS_HEIGHT 600
#define KEY_DOWN(vk) (GetAsyncKeyState(vk)&0x8000 ? 1 : 0)

//ȫ�ֺ���
BOOL g_Init(HWND hwnd,HINSTANCE hInstance, WPARAM wParam, LPARAM lParam);
BOOL g_Init_MAIN(HWND hwnd,WPARAM wParam,LPARAM lParam,CModule*& cmodule);//��һ������Ϊ�����ھ�������һ������Ϊ��һ������
BOOL g_Init_QUERY(HWND hwnd, WPARAM wParam, LPARAM lParam, CModule*& cmmodule);//ͬ��
BOOL g_Destroy(HWND hwnd);

//ȫ�ֱ���
/*
����ģ��˵����
module[0]:��¼���� module[1]:������ module[2]:��Ϣ¼����� module[3]:��Ϣ��ѯ���棬module[4]:������ѯ
*/
HINSTANCE ghinstance = NULL;
HWND gwindow = NULL;
MOUDLEFLAG gflag;
CModule* module[6];//�Ÿ�����ģ��,��4��ģ����ͬ������ֻ������Ϊ5�ľ͹���
BSTRUCTARR barr;
ESTRUCTARR earr;
//���ݿ�����ӳ�ʼ���ڵ�½����
sql::Driver* driver = NULL;
sql::Connection* conn = NULL;
sql::Statement* stmt = NULL;
sql::ResultSet* res = NULL;

//windows progress
LRESULT CALLBACK MyProc(HWND hwnd, UINT umsg, WPARAM wParam, LPARAM lParam);//��wparam �� lparam

//WinMain
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nShowCmd)
{
	//�������
	WNDCLASSEX mywindowclass;
	mywindowclass.cbSize = sizeof(WNDCLASSEX);
	mywindowclass.hInstance = hInstance;
	mywindowclass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC | CS_DBLCLKS;
	mywindowclass.lpfnWndProc = MyProc;
	mywindowclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	mywindowclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	mywindowclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	mywindowclass.hIconSm = NULL;
	mywindowclass.lpszClassName = WINDOWSCLASS_NAME;
	mywindowclass.cbClsExtra = 0;
	mywindowclass.cbWndExtra = 0;
	mywindowclass.lpszMenuName = NULL;

	//����ע��
	if(!RegisterClassEx(&mywindowclass))
	{
		MessageBox(NULL, TEXT("error"), TEXT("������ע��ʧ�ܣ�"), MB_OK);
		return (0);
	}
	ghinstance = hInstance;

	//�����ڴ���
	HWND hwnd;
	if(!(hwnd = CreateWindow(WINDOWSCLASS_NAME,WINDOWS_NAME,WS_OVERLAPPEDWINDOW,300,200,WINDOWS_WIDTH,WINDOWS_HEIGHT,NULL,NULL,ghinstance,NULL)))
	{
		MessageBox(NULL, TEXT("error"), TEXT("���ڴ���ʧ�ܣ�"), MB_OK);
		return (0);
	}
	gwindow = hwnd;

	//��ʾ�����
	ShowWindow(gwindow,nShowCmd);
	UpdateWindow(gwindow);

	//��Ϣѭ��
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	//������ע��
	UnregisterClass(WINDOWSCLASS_NAME, ghinstance);
	return (0);
}

LRESULT CALLBACK MyProc(HWND hwnd, UINT umsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = NULL;

	switch (umsg)
	{
	case WM_CREATE:
	{
		if (!g_Init(hwnd, ghinstance, wParam, lParam))
		{
			MessageBox(NULL, _TEXT("��ʼ��ʧ�ܣ�"), _TEXT("error"), MB_OK);
		}
		return 0;
	}break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		if (gflag == LOG)
		{
			TextOut(hdc, 200, 185, _TEXT("�û���"), wcslen(_TEXT("�û���")));
			TextOut(hdc, 200, 235, _TEXT("����"), wcslen(_TEXT("����")));

			HFONT hfont = CreateFont(-25, -12.5, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hfont);
			TextOut(hdc, 200, 50, _TEXT("��ӭ��������Ԥ��ϵͳ"), wcslen(_TEXT("��ӭ��������Ԥ��ϵͳ")));
			DeleteObject(hfont);

			HFONT hf = CreateFont(-14, -7, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hf);
			TextOut(hdc, 200, 500, _TEXT("Copyright-@2018 chengyuxiang"), wcslen(_TEXT("Copyright-@2018 chengyuxiang")));
			DeleteObject(hf);
		}
		else if (gflag == MAIN)
		{
			SetTextColor(hdc, RGB(255, 255, 255));
			TextOut(hdc, 200, 185, _TEXT("�û���"), wcslen(_TEXT("�û���")));
			TextOut(hdc, 200, 235, _TEXT("����"), wcslen(_TEXT("����")));
		}
		else if (gflag == RECORD)
		{
			//���ָ���
			HPEN hpen = CreatePen(PS_SOLID, 1, RGB(0,0,0));
			SelectObject(hdc, hpen);
			int lx = 10; int ly = 35;
			for (int i = 0; i < 3; ++i)
			{
				MoveToEx(hdc, lx, ly, NULL);
				LineTo(hdc, WINDOWS_WIDTH - 30, ly);
				ly += 150;
			}
			DeleteObject(hpen);

			//д��
			HFONT hfont = CreateFont(-18, -9, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hfont);

			TextOut(hdc, 280, 38, _TEXT("������Ϣ�Ǽ�"), wcslen(_TEXT("������Ϣ�Ǽ�")));
			TextOut(hdc, 35, 105, _TEXT("����"), wcslen(_TEXT("����")));
			TextOut(hdc, 210, 105, _TEXT("������"), wcslen(_TEXT("������")));
			TextOut(hdc, 410, 105, _TEXT("Ŀ�ĵ�"), wcslen(_TEXT("Ŀ�ĵ�")));

			TextOut(hdc, 280, 188, _TEXT("ס�޼��ͳ��Ǽ�"), wcslen(_TEXT("ס�޼��ͳ��Ǽ�")));
			TextOut(hdc, 15, 255, _TEXT("�ùݵ�"), wcslen(_TEXT("�ù����ڵ�")));
			TextOut(hdc, 175, 255, _TEXT("�ͳ����ڵ�"), wcslen(_TEXT("�ͳ����ڵ�")));

			TextOut(hdc, 280, 338, _TEXT("�ͻ���Ϣ�Ǽ�"), wcslen(_TEXT("�ͻ���Ϣ�Ǽ�")));
			TextOut(hdc, 35, 405, _TEXT("����"), wcslen(_TEXT("����")));
			TextOut(hdc, 195, 405, _TEXT("���֤��"), wcslen(_TEXT("���֤��")));

			DeleteObject(hfont);


		}
		else if (gflag == FLIGHT)
		{ 
			HFONT hfont = CreateFont(-25, -12.5, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hfont);
			TextOut(hdc, 200, 50, _TEXT("�����ѯ"), wcslen(_TEXT("�����ѯ")));

			DeleteObject(hfont);

			HFONT hf = CreateFont(-18, -9, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hf);
			TextOut(hdc, 95, 255, _TEXT("�����"), wcslen(_TEXT("�����")));
			DeleteObject(hf);
		}
		else if(gflag == BUS)
		{ 
			HFONT hfont = CreateFont(-25, -12.5, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hfont);
			TextOut(hdc, 200, 50, _TEXT("�ͳ���ѯ"), wcslen(_TEXT("�ͳ���ѯ")));

			DeleteObject(hfont);

			HFONT hf = CreateFont(-18, -9, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hf);
			TextOut(hdc, 95, 255, _TEXT("�ͳ���"), wcslen(_TEXT("�ͳ���")));
			DeleteObject(hf);
		}
		else if(gflag == HOTEL)
		{ 
			HFONT hfont = CreateFont(-25, -12.5, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hfont);
			TextOut(hdc, 200, 50, _TEXT("�ùݲ�ѯ"), wcslen(_TEXT("�ùݲ�ѯ")));

			DeleteObject(hfont);

			HFONT hf = CreateFont(-18, -9, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hf);
			TextOut(hdc, 95, 255, _TEXT("�ùݵ�"), wcslen(_TEXT("�ùݵ�")));
			DeleteObject(hf);
		}
		else if (gflag == TRAIVEL)
		{
			HFONT hfont = CreateFont(-25, -12.5, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hfont);
			TextOut(hdc, 200, 50, _TEXT("����·�߲�ѯ"), wcslen(_TEXT("����·�߲�ѯ")));

			DeleteObject(hfont);

			HFONT hf = CreateFont(-18, -9, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
				DEFAULT_QUALITY, FF_MODERN, _TEXT("����"));
			SelectObject(hdc, hf);
			TextOut(hdc, 95, 255, _TEXT("�ͻ���"), wcslen(_TEXT("�ͻ���")));
			DeleteObject(hf);
		}
		
		EndPaint(hwnd,&ps);
		return (0);
	}break;

	case WM_COMMAND:
	{
		switch (wParam)
		{
		case BN_CLICKED:
		{
			//�����¼��Ϣ���������Ϊ������
			if (gflag == LOG)
			{
				//�������ݿ�
				char username[50];
				char password[50];
				_TCHAR wusername[50] = _TEXT(" ");
				_TCHAR wpassword[50] = _TEXT(" ");
				bool success = true;
				if (module[0]->MyGetconect(module[0]->MyGetEA(0), wusername))
				{
					if (module[0]->MyGetconect(module[0]->MyGetEA(1), wpassword))
					{
						WideCharToMultiByte(CP_ACP, 0, wusername, wcslen(wusername)+1, username, sizeof(username), 0, 0);
						WideCharToMultiByte(CP_ACP, 0, wpassword, wcslen(wpassword)+1, password, sizeof(password), 0, 0);//ע�⣬Ӧ�ð�ת��Դ�ġ�\0��ҲҪһ��ת��
						try {
							driver = get_driver_instance();
							conn = driver->connect("tcp://127.0.0.1:3306", username, password);
							conn->setSchema("travel");
							stmt = conn->createStatement();
						}
						catch (sql::SQLException& e)
						{
							success = false;
							_TCHAR errfile[200];
							char tmp[200];
							sprintf_s(tmp, 200, "error file: %s ...err: %s",__FILE__,e.what());
							MultiByteToWideChar(CP_ACP, 0, tmp, strlen(tmp), errfile, sizeof(errfile)/sizeof(errfile[0]));
							MessageBox(NULL, errfile, _TEXT("error"), MB_OK);
						}
					}
				}
				//�л���������
				if (success)
				{
					gflag = MAIN;
					if (!g_Init_MAIN(hwnd, wParam, lParam, module[0]))
					{
						MessageBox(NULL, _TEXT("�������ʼ��ʧ�ܣ�"), _TEXT("error"), MB_OK);
					}
				}
				return 0;
			}
			//����������
			else if(gflag == MAIN)
			{
				if ((HWND)lParam == module[1]->MyGetBA(0))
				{
					gflag = RECORD;
					module[1]->MyDestory();//���������
					MoveWindow(hwnd, 300, 200, WINDOWS_WIDTH - 1, WINDOWS_HEIGHT, TRUE);
					//���ð�ť
					barr[0].x = 200; barr[0].y = 500; barr[0].height = 25; barr[0].wedth = 50;
					barr[1].x = 280; barr[1].y = 500; barr[1].height = 25; barr[1].wedth = 50;
					barr[1].identy = _TEXT("����"); barr[0].identy = _TEXT("ȷ��");

					//���ñ༭��
					UINT ex = 70; UINT ey = 100;
					for (int i = 0; i < 7; ++i)
					{
						earr[i].x = ex; earr[i].y = ey;
						earr[i].height = 25; earr[i].wedth = 100;
						earr[i].identy = NULL;
						ex += 200;
						if (i && i % 2 == 0)
						{
							ex = 70; ey += 150;
						}
					}
					module[2]->MyCreateBotton(hwnd, ghinstance, barr, wParam, lParam);
					module[2]->MyCreateEdit(hwnd, ghinstance, earr, wParam, lParam);

				}
				else if ((HWND)lParam == module[1]->MyGetBA(1))
				{
					gflag = QUERY;
					module[1]->MyDestory();//����������
					MoveWindow(hwnd, 300, 200, WINDOWS_WIDTH + 1, WINDOWS_HEIGHT, TRUE);
					barr[0].x = 150; barr[0].y = 150; barr[0].height = 25; barr[0].wedth = 100; barr[0].identy = _TEXT("�����ѯ");
					barr[1].x = 290; barr[1].y = 150; barr[1].height = 25; barr[1].wedth = 100; barr[1].identy = _TEXT("�ͳ���ѯ");
					barr[2].x = 150; barr[2].y = 190; barr[2].height = 25; barr[2].wedth = 100; barr[2].identy = _TEXT("�ùݲ�ѯ");
					barr[3].x = 290; barr[3].y = 190; barr[3].height = 25; barr[3].wedth = 150; barr[3].identy = _TEXT("����·�߲�ѯ");
					barr[4].x = 275; barr[4].y = 230; barr[4].height = 25; barr[4].wedth = 50; barr[4].identy = _TEXT("����");
					module[3]->MyCreateBotton(hwnd, ghinstance, barr, wParam, lParam);
				}
				else if ((HWND)lParam == module[1]->MyGetBA(2))
				{
					g_Destroy(hwnd);
					PostQuitMessage(0);
				}
				return 0;
			}
			//������Ϣ¼��
			else if (gflag == RECORD)
			{
				//�����ȷ��
				if ((HWND)lParam == module[2]->MyGetBA(0))
				{
					char record[8][21];
					for (int i = 0; i < 8; ++i)
					{
						memset(record[i], 0, sizeof(record[i]));
					}

					for (int i = 0; i < 7; ++i)
					{
						_TCHAR wrecord[21] = _TEXT(" ");
						int irlength = module[2]->MyGetconect(module[2]->MyGetEA(i), wrecord);
						if (irlength > 20)
						{
							MessageBox(NULL, _TEXT("�ַ�����20���޷���ȡ!"), _TEXT("error"), MB_OK);
							return 0;
						}
						else
						{
							WideCharToMultiByte(CP_ACP, 0, wrecord, wcslen(wrecord) + 1, record[i], sizeof(record[i]), 0, 0);
						}
					}

					//��Ϣ¼�����ݿ�
					try {
						//���ùر��Զ��ύ
						conn->setAutoCommit(false);
						bool queryok = true;

						if (record[0][0] != ' ' && record[1][0] != ' ' && record[2][0] != ' ')
						{
							bool haved = false;
							char sqlstr[200];
							char sqlupdate[200];
							memset(sqlstr, 0, sizeof(sqlstr));
							memset(sqlupdate, 0, sizeof(sqlupdate));

							sprintf_s(sqlstr, 200, "select * from flight where flightnum = '%s'", record[0]);
							//����иú��࣬��ֻ������Ч��λ��
							res = stmt->executeQuery(sqlstr);
							while (res->next())
							{
								haved = true;
								if (res->getString("fromcity") != record[1] || res->getString("arivecity") != record[2])
								{
									MessageBox(NULL, _TEXT("���������ʼ��ַ��ִ��ַ����"), _TEXT("error"), MB_OK);
									queryok = false;
								}
								if (res->getInt("numavail") <= 0)
								{
									sprintf_s(sqlupdate, 200, "update flight set numavail = 0 where flightnum = '%s'", record[0]);
									stmt->executeUpdate(sqlupdate);
									MessageBox(NULL, _TEXT("��Ԥ���ĺ��������أ�������ѡ��"), _TEXT("tip"), MB_OK);
									queryok = false;
								}
								else
								{
									sprintf_s(sqlupdate, 200, "update flight set numavail = numavail-1 where flightnum = '%s'", record[0]);
									stmt->executeUpdate(sqlupdate);
								}
							}
							//���򣬲���һ�º���
							if (!haved)
							{
								sprintf_s(sqlupdate, 200, "insert into flight values('%s',500,100,99,'%s','%s')", record[0], record[1], record[2]);
								stmt->executeUpdate(sqlupdate);
							}
						}
						if (record[3][0] != ' ')
						{
							bool haved = false;
							char sqlstr[200];
							char sqlupdate[200];
							memset(sqlstr, 0, sizeof(sqlstr));
							memset(sqlupdate, 0, sizeof(sqlupdate));

							sprintf_s(sqlstr, 200, "select * from hotel where location = '%s'", record[3]);
							res = stmt->executeQuery(sqlstr);
							while (res->next())
							{
								haved = true;
								if (res->getInt("numavail") <= 0)
								{
									sprintf_s(sqlupdate, 200, "update hotel set numavail = 0 where location = '%s'", record[3]);
									stmt->executeUpdate(sqlupdate);
									MessageBox(NULL, _TEXT("��ѡ����ù�������������ѡ��"), _TEXT("tip"), MB_OK);
									queryok = false;
								}
								else
								{
									sprintf_s(sqlupdate, 200, "update hotel set numavail = numavail-1 where location = '%s'", record[3]);
									stmt->executeUpdate(sqlupdate);
								}
							}
							if (!haved)
							{
								sprintf_s(sqlupdate, 200, "insert into hotel values('%s',300,200,199)", record[3]);
								stmt->executeUpdate(sqlupdate);
							}
						}
						if (record[4][0] != ' ')
						{
							bool haved = false;
							char sqlstr[200];
							char sqlupdate[200];
							memset(sqlstr, 0, sizeof(sqlstr));
							memset(sqlupdate, 0, sizeof(sqlupdate));

							sprintf_s(sqlstr, 200, "select * from bus where location = '%s'", record[4]);
							res = stmt->executeQuery(sqlstr);
							while (res->next())
							{
								haved = true;
								if (res->getInt("numavail") <= 0)
								{
									sprintf_s(sqlupdate, 200, "update bus set numavail = 0 where location = '%s'", record[4]);
									stmt->executeUpdate(sqlupdate);
									MessageBox(NULL, _TEXT("��ѡ��Ŀͳ�������������ѡ��"), _TEXT("tip"), MB_OK);
									queryok = false;
								}
								else
								{
									sprintf_s(sqlupdate, 200, "update bus set numavail = numavail-1 where location = '%s'", record[4]);
									stmt->executeUpdate(sqlupdate);
								}
							}
							if (!haved)
							{
								sprintf_s(sqlupdate, 200, "insert into bus values('%s',50,200,199)", record[4]);
								stmt->executeUpdate(sqlupdate);
							}
						}
						if (record[5][0] != ' ' && record[6][0] != ' ')
						{
							char sqlupdate[200];
							memset(sqlupdate, 0, sizeof(sqlupdate));

							sprintf_s(sqlupdate, 200, "insert into customers values('%s','%s')", record[5], record[6]);
							stmt->executeUpdate(sqlupdate);

							if (record[0][0] != ' ')
							{
								//��־0����ɻ�
								memset(sqlupdate, 0, sizeof(sqlupdate));
								sprintf_s(sqlupdate, 200, "insert into reservation values('%s',0,'%s')", record[5], record[0]);
								stmt->executeUpdate(sqlupdate);//error
							}
							if (record[3][0] != ' ')
							{
								//��־2�����ù�
								memset(sqlupdate, 0, sizeof(sqlupdate));
								sprintf_s(sqlupdate, 200, "insert into reservation values('%s',2,'%s')", record[5], record[3]);
								stmt->executeUpdate(sqlupdate);
							}
							if (record[4][0] != ' ')
							{
								//��־1��������
								memset(sqlupdate, 0, sizeof(sqlupdate));
								sprintf_s(sqlupdate, 200, "insert into reservation values('%s',1,'%s')", record[5], record[4]);
								stmt->executeUpdate(sqlupdate);
							}
						}
						else
						{
							MessageBox(NULL, _TEXT("�û���Ϣ��ȫ���뽫���������֤��ȫ��"), _TEXT("error"), MB_OK);
							queryok = false;
						}

						//�����ɹ����ύ������ع�
						if (queryok)
						{
							MessageBox(NULL, _TEXT("��Ϣ�Ǽǳɹ���"), _TEXT("successful"), MB_OK);
							conn->commit();
						}
						else
						{
							conn->rollback();
						}

					}
					catch (sql::SQLException& e)
					{
						char myerror[100];
						_TCHAR wmyerror[100];
						strcpy_s(myerror, 100, e.what());
						MultiByteToWideChar(CP_ACP, 0, myerror, strlen(myerror) + 1, wmyerror, sizeof(wmyerror) / sizeof(wmyerror[0]));
						MessageBox(NULL, wmyerror, _TEXT("error"), MB_OK);
					}

					return 0;
				}
				//����˷���
				else if ((HWND)lParam == module[2]->MyGetBA(1))
				{
					gflag = MAIN;
					g_Init_MAIN(hwnd, wParam, lParam, module[2]);
					return 0;
				}
			}
			//������Ϣ��ѯ������
			else if (gflag == QUERY)
			{
				//����� �����ѯ
				if ((HWND)lParam == module[3]->MyGetBA(0))
				{
					gflag = FLIGHT;
					module[3]->MyDestory();//���ٲ�ѯ����
					MoveWindow(hwnd, 300, 200, WINDOWS_WIDTH - 1, WINDOWS_HEIGHT, TRUE);
					barr[0].x = 150; barr[0].y = 300; barr[0].height = 25; barr[0].wedth = 50; barr[0].identy = _TEXT("ȷ��");
					barr[1].x = 225; barr[1].y = 300; barr[1].height = 25; barr[1].wedth = 50; barr[1].identy = _TEXT("����");
					earr[0].x = 150; earr[0].y = 250; earr[0].height = 25; earr[0].wedth = 200; earr[0].identy = NULL;
					module[4]->MyCreateBotton(hwnd, ghinstance, barr, wParam, lParam);
					module[4]->MyCreateEdit(hwnd, ghinstance, earr, wParam, lParam);
					return 0;
				}
				//����� �ͳ���ѯ
				if ((HWND)lParam == module[3]->MyGetBA(1))
				{
					gflag = BUS;
					module[3]->MyDestory();//���ٲ�ѯ����
					MoveWindow(hwnd, 300, 200, WINDOWS_WIDTH - 1, WINDOWS_HEIGHT, TRUE);
					barr[0].x = 150; barr[0].y = 300; barr[0].height = 25; barr[0].wedth = 50; barr[0].identy = _TEXT("ȷ��");
					barr[1].x = 225; barr[1].y = 300; barr[1].height = 25; barr[1].wedth = 50; barr[1].identy = _TEXT("����");
					earr[0].x = 150; earr[0].y = 250; earr[0].height = 25; earr[0].wedth = 200; earr[0].identy = NULL;
					module[4]->MyCreateBotton(hwnd, ghinstance, barr, wParam, lParam);
					module[4]->MyCreateEdit(hwnd, ghinstance, earr, wParam, lParam);
					return 0;
				}
				//����� �ùݲ�ѯ
				if ((HWND)lParam == module[3]->MyGetBA(2))
				{
					gflag = HOTEL;
					module[3]->MyDestory();//���ٲ�ѯ����
					MoveWindow(hwnd, 300, 200, WINDOWS_WIDTH - 1, WINDOWS_HEIGHT, TRUE);
					barr[0].x = 150; barr[0].y = 300; barr[0].height = 25; barr[0].wedth = 50; barr[0].identy = _TEXT("ȷ��");
					barr[1].x = 225; barr[1].y = 300; barr[1].height = 25; barr[1].wedth = 50; barr[1].identy = _TEXT("����");
					earr[0].x = 150; earr[0].y = 250; earr[0].height = 25; earr[0].wedth = 200; earr[0].identy = NULL;
					module[4]->MyCreateBotton(hwnd, ghinstance, barr, wParam, lParam);
					module[4]->MyCreateEdit(hwnd, ghinstance, earr, wParam, lParam);
					return 0;
				}
				//����� ����·�߲�ѯ
				if ((HWND)lParam == module[3]->MyGetBA(3))
				{
					gflag = TRAIVEL;
					module[3]->MyDestory();//���ٲ�ѯ����
					MoveWindow(hwnd, 300, 200, WINDOWS_WIDTH - 1, WINDOWS_HEIGHT, TRUE);
					barr[0].x = 150; barr[0].y = 300; barr[0].height = 25; barr[0].wedth = 50; barr[0].identy = _TEXT("ȷ��");
					barr[1].x = 225; barr[1].y = 300; barr[1].height = 25; barr[1].wedth = 50; barr[1].identy = _TEXT("����");
					earr[0].x = 150; earr[0].y = 250; earr[0].height = 25; earr[0].wedth = 200; earr[0].identy = NULL;
					module[4]->MyCreateBotton(hwnd, ghinstance, barr, wParam, lParam);
					module[4]->MyCreateEdit(hwnd, ghinstance, earr, wParam, lParam);
					return 0;
				}
				//����� ����
				if ((HWND)lParam == module[3]->MyGetBA(4))
				{
					gflag = MAIN;
					g_Init_MAIN(hwnd, wParam, lParam, module[3]);
					return 0;
				}
			}
			//��Ϣ��ѯ�ֽ���
			else if (gflag == FLIGHT)
			{
				//�����ȷ��
				if ((HWND)lParam == module[4]->MyGetBA(0))
				{
					_TCHAR wflight[21] = _TEXT(" ");
					char flight[21];
					char fsqlstr[100];
					char sqlerr[100];
					_TCHAR wsqlerr[100] = _TEXT(" ");
					memset(fsqlstr, 0, sizeof(fsqlstr));
					memset(flight, 0, sizeof(flight));
					memset(sqlerr, 0, sizeof(sqlerr));

					if (module[4]->MyGetconect(module[4]->MyGetEA(0), wflight) > 20)
					{
						MessageBox(NULL, _TEXT("��������ַ����ܳ���20!"), _TEXT("error"), MB_OK);
					}
					else
					{
						try {
							bool queryok = false;
							char resultion[100];
							_TCHAR wresultion[100] = _TEXT(" ");
							memset(resultion, 0, sizeof(resultion));

							WideCharToMultiByte(CP_ACP, 0, wflight, wcslen(wflight) + 1, flight, sizeof(flight), 0, 0);
							sprintf_s(fsqlstr, 100, "select * from flight where flightnum = '%s'", flight);
							res = stmt->executeQuery(fsqlstr);
							while (res->next())
							{
								queryok = true;
								sprintf_s(resultion, 100, "%s�ź���۸�Ϊ%d,�ɶ���λ��Ϊ%d���ú�����%s����%s", flight, res->getInt("price"), res->getInt("numavail"),
									res->getString("fromcity").c_str(), res->getString("arivecity").c_str());
								MultiByteToWideChar(CP_ACP, 0, resultion, strlen(resultion) + 1, wresultion, sizeof(wresultion) / sizeof(wresultion[0]));
								MessageBox(NULL, wresultion, _TEXT("��ѯ���"), MB_OK);
							}
							if (!queryok)
							{
								MessageBox(NULL, _TEXT("������˼������ѯ�ĺ������ޣ�"), _TEXT("tip"), MB_OK);
							}
						}
						catch (sql::SQLException& e)
						{
							strcpy_s(sqlerr, 100, e.what());
							MultiByteToWideChar(CP_ACP, 0, sqlerr, strlen(sqlerr) + 1, wsqlerr, sizeof(wsqlerr) / sizeof(wsqlerr[0]));
							MessageBox(NULL, wsqlerr, _TEXT("error"), MB_OK);
						}
					}
				}
				//����˷���
				else if ((HWND)lParam == module[4]->MyGetBA(1))
				{
					gflag = QUERY;
					g_Init_QUERY(hwnd, wParam, lParam, module[4]);
				}
				return 0;
			}
			else if (gflag == BUS)
			{
				//�����ȷ��
				if ((HWND)lParam == module[4]->MyGetBA(0))
				{
					_TCHAR wbus[21] = _TEXT(" ");
					char bus[21];
					char fsqlstr[100];
					char sqlerr[100];
					_TCHAR wsqlerr[100] = _TEXT(" ");
					memset(fsqlstr, 0, sizeof(fsqlstr));
					memset(bus, 0, sizeof(bus));
					memset(sqlerr, 0, sizeof(sqlerr));

					if (module[4]->MyGetconect(module[4]->MyGetEA(0), wbus) > 20)
					{
						MessageBox(NULL, _TEXT("��������ַ����ܳ���20!"), _TEXT("error"), MB_OK);
					}
					else
					{
						try {
							bool queryok = false;
							char resultion[100];
							_TCHAR wresultion[100] = _TEXT(" ");
							memset(resultion, 0, sizeof(resultion));

							WideCharToMultiByte(CP_ACP, 0, wbus, wcslen(wbus) + 1, bus, sizeof(bus), 0, 0);
							sprintf_s(fsqlstr, 100, "select * from bus where location = '%s'", bus);//��Ķ�
							res = stmt->executeQuery(fsqlstr);
							while (res->next())
							{
								queryok = true;
								sprintf_s(resultion, 100, "%s�������۸�Ϊ%d,�ɶ���λ��Ϊ%d��", bus, res->getInt("price"), res->getInt("numavail"));
								MultiByteToWideChar(CP_ACP, 0, resultion, strlen(resultion) + 1, wresultion, sizeof(wresultion) / sizeof(wresultion[0]));
								MessageBox(NULL, wresultion, _TEXT("��ѯ���"), MB_OK);
							}
							if (!queryok)
							{
								MessageBox(NULL, _TEXT("������˼������ѯ�ĺ������ޣ�"), _TEXT("tip"), MB_OK);
							}
						}
						catch (sql::SQLException& e)
						{
							strcpy_s(sqlerr, 100, e.what());
							MultiByteToWideChar(CP_ACP, 0, sqlerr, strlen(sqlerr) + 1, wsqlerr, sizeof(wsqlerr) / sizeof(wsqlerr[0]));
							MessageBox(NULL, wsqlerr, _TEXT("error"), MB_OK);
						}
					}
				}
				//����˷���
				else if ((HWND)lParam == module[4]->MyGetBA(1))
				{
					gflag = QUERY;
					g_Init_QUERY(hwnd, wParam, lParam, module[4]);
				}
				return 0;
			}
			else if (gflag == HOTEL)
			{
				//�����ȷ��
				if ((HWND)lParam == module[4]->MyGetBA(0))
				{
					_TCHAR whotel[21] = _TEXT(" ");
					char hotel[21];
					char fsqlstr[100];
					char sqlerr[100];
					_TCHAR wsqlerr[100] = _TEXT(" ");
					memset(fsqlstr, 0, sizeof(fsqlstr));
					memset(hotel, 0, sizeof(hotel));
					memset(sqlerr, 0, sizeof(sqlerr));

					if (module[4]->MyGetconect(module[4]->MyGetEA(0), whotel) > 20)
					{
						MessageBox(NULL, _TEXT("��������ַ����ܳ���20!"), _TEXT("error"), MB_OK);
					}
					else
					{
						try {
							bool queryok = false;
							char resultion[100];
							_TCHAR wresultion[100] = _TEXT(" ");
							memset(resultion, 0, sizeof(resultion));

							WideCharToMultiByte(CP_ACP, 0, whotel, wcslen(whotel) + 1, hotel, sizeof(hotel), 0, 0);
							sprintf_s(fsqlstr, 100, "select * from hotel where location = '%s'", hotel);//��Ķ�
							res = stmt->executeQuery(fsqlstr);
							while (res->next())
							{
								queryok = true;
								sprintf_s(resultion, 100, "%s���ùݼ۸�Ϊ%d,�ɶ�������Ϊ%d��", hotel, res->getInt("price"), res->getInt("numavail"));
								MultiByteToWideChar(CP_ACP, 0, resultion, strlen(resultion) + 1, wresultion, sizeof(wresultion) / sizeof(wresultion[0]));
								MessageBox(NULL, wresultion, _TEXT("��ѯ���"), MB_OK);
							}
							if (!queryok)
							{
								MessageBox(NULL, _TEXT("������˼������ѯ�ĺ������ޣ�"), _TEXT("tip"), MB_OK);
							}
						}
						catch (sql::SQLException& e)
						{
							strcpy_s(sqlerr, 100, e.what());
							MultiByteToWideChar(CP_ACP, 0, sqlerr, strlen(sqlerr) + 1, wsqlerr, sizeof(wsqlerr) / sizeof(wsqlerr[0]));
							MessageBox(NULL, wsqlerr, _TEXT("error"), MB_OK);
						}
					}
				}
				//����˷���
				else if ((HWND)lParam == module[4]->MyGetBA(1))
				{
					gflag = QUERY;
					g_Init_QUERY(hwnd, wParam, lParam, module[4]);
				}
				return 0;
			}
			else if (gflag == TRAIVEL)
			{
				//�����ȷ��
				if ((HWND)lParam == module[4]->MyGetBA(0))
				{
					_TCHAR wtravel[21] = _TEXT(" ");
					char travel[21];
					char fsqlstr[100];
					char sqlerr[100];
					_TCHAR wsqlerr[100] = _TEXT(" ");
					memset(fsqlstr, 0, sizeof(fsqlstr));
					memset(travel, 0, sizeof(travel));
					memset(sqlerr, 0, sizeof(sqlerr));

					if (module[4]->MyGetconect(module[4]->MyGetEA(0), wtravel) > 20)
					{
						MessageBox(NULL, _TEXT("��������ַ����ܳ���20!"), _TEXT("error"), MB_OK);
					}
					else
					{
						try {
							char resultion[100];
							char tmp[100];
							_TCHAR wresultion[100] = _TEXT(" ");
							memset(resultion, 0, sizeof(resultion));
							memset(tmp, 0, sizeof(tmp));

							WideCharToMultiByte(CP_ACP, 0, wtravel, wcslen(wtravel) + 1, travel, sizeof(travel), 0, 0);
							sprintf_s(fsqlstr, 100, "select * from reservation where custname = '%s'", travel);//��Ķ�
							res = stmt->executeQuery(fsqlstr);
							while (res->next())
							{
								sql::ResultSet* tres = NULL;
								if (res->getInt("resvtype") == 0)
								{
									sprintf_s(tmp, sizeof(tmp), "select * from flight where flightnum = '%s'", res->getString("resvkey"));
									tres = stmt->executeQuery(tmp);
									while (tres->next())
									{
										sprintf_s(resultion, sizeof(resultion), "�û�%s������%s�����%s����%s,", travel, res->getString("resvkey"),
											tres->getString("fromcity"),tres->getString("arivecity"));
									}
								}
								if (res->getInt("resvtype") == 1)
								{
									memset(tmp, 0, sizeof(tmp));
									sprintf_s(tmp, sizeof(tmp), "��%s�����ͳ��۹⣬",res->getString("resvkey"));
									strcat_s(resultion, sizeof(resultion), tmp);
								}
								if (res->getInt("resvtype") == 2)
								{
									memset(tmp, 0, sizeof(tmp));
									sprintf_s(tmp, sizeof(tmp), "����%s���ù���ס��",res->getString("resvkey"));
									strcat_s(resultion, sizeof(resultion), tmp);
								}
								
								if (tres)
								{
									delete tres;
									tres = NULL;
								}
							}

							if (!resultion[0])
							{
								MessageBox(NULL, _TEXT("���޴˼�¼��"), _TEXT("tip"), MB_OK);
							}
							else
							{
								MultiByteToWideChar(CP_ACP, 0, resultion, strlen(resultion) + 1, wresultion, sizeof(wresultion) / sizeof(wresultion[0]));
								MessageBox(NULL, wresultion, _TEXT("��ѯ���"), MB_OK);
							}
						}
						catch (sql::SQLException& e)
						{
							strcpy_s(sqlerr, 100, e.what());
							MultiByteToWideChar(CP_ACP, 0, sqlerr, strlen(sqlerr) + 1, wsqlerr, sizeof(wsqlerr) / sizeof(wsqlerr[0]));
							MessageBox(NULL, wsqlerr, _TEXT("error"), MB_OK);
						}
					}
				}
				//����˷���
				else if ((HWND)lParam == module[4]->MyGetBA(1))
				{
					gflag = QUERY;
					g_Init_QUERY(hwnd, wParam, lParam, module[4]);
				}
				return 0;
			}
		}break;

		default:break;
		}
	}

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
		{
			g_Destroy(hwnd);
			PostQuitMessage(0);
			return (0);
		}break;

		default:break;
		}
	}break;

	case WM_DESTROY:
	{
		g_Destroy(hwnd);
		PostQuitMessage(0);
		return (0);
	}break;

	default:
		break;
	}
	return DefWindowProc(hwnd, umsg, wParam, lParam);
}

BOOL g_Init(HWND hwnd,HINSTANCE hInstance,WPARAM wParam,LPARAM lParam)
{
	////�����ַ�ת��Ϊխ�ַ�
	//_TCHAR* user;
	//_TCHAR* password;
	//char* username;
	//char* psd;
	//WideCharToMultiByte(CP_ACP, 0, user, -1, username, wcslen(user) + 1, 0, 0);
	//WideCharToMultiByte(CP_ACP, 0, password, -1, psd, wcslen(password) + 1, 0, 0);
	gflag = LOG;
	module[0] = new CModule(1, 2);
	module[1] = new CModule(3, 0);
	module[2] = new CModule(2, 7);
	module[3] = new CModule(5, 0);
	module[4] = new CModule(2, 1);

	//��ʼ����¼����
	barr[0].x = 250; barr[0].y = 300;
	barr[0].height = 25;
	barr[0].wedth = 50;
	barr[0].identy = _TEXT("��¼");
	earr[0].x = 250; earr[0].y = 180;
	earr[1].x = 250; earr[1].y = 230;
	earr[0].height = earr[1].height = 25; earr[0].wedth = earr[1].wedth = 150;
	earr[0].identy = earr[1].identy = NULL;

	if (!module[0]->MyCreateBotton(hwnd, hInstance, barr, wParam, lParam))
	{
		return FALSE;
	}
	if (!module[0]->MyCreateEdit(hwnd, hInstance, earr, wParam, lParam,ES_PASSWORD))
	{
		return FALSE;
	}
	return TRUE;

}

BOOL g_Destroy(HWND hwnd)
{
	//�����ж����ݿ������
	if (res)
	{
		delete res;
		res = NULL;
	}
	if (stmt)
	{
		delete stmt;
		stmt = NULL;
	}
	if (conn)
	{
		delete conn;
		conn = NULL;
	}

	//����ģ��
	module[0]->MyDestory();
	module[1]->MyDestory();
	module[2]->MyDestory();
	module[3]->MyDestory();
	module[4]->MyDestory();
	for (int i = 0; i < 3; ++i)
	{
		if (module[i])
		{
			delete module[i];
			module[i] = NULL;
		}
	}
	return TRUE;
}

BOOL g_Init_MAIN(HWND hwnd,WPARAM wParam,LPARAM lParam,CModule*& cmodule)
{
	cmodule->MyDestory();//�����ٵ�¼����
	MoveWindow(hwnd, 300, 200, WINDOWS_WIDTH + 1, WINDOWS_HEIGHT, TRUE);//��д�ⲽΪʲô��������˽����ϵ��ַ���
																		//���ð�ťλ��
	barr[0].x = 250; barr[0].y = 200;
	barr[0].wedth = 100; barr[0].height = 25;
	barr[0].identy = _TEXT("��Ϣ¼��");
	barr[1].x = 250; barr[1].y = 250;
	barr[1].height = 25; barr[1].wedth = 100;
	barr[1].identy = _TEXT("��Ϣ��ѯ");
	barr[2].x = 250; barr[2].y = 300; barr[2].height = 25; barr[2].wedth = 100; barr[2].identy = _TEXT("�˳�");
	module[1]->MyCreateBotton(hwnd, ghinstance, barr, wParam, lParam);
	return TRUE;
}

BOOL g_Init_QUERY(HWND hwnd, WPARAM wParam, LPARAM lParam, CModule*& cmmodule)
{
	cmmodule->MyDestory();//���ٲ�ѯ�ֽ���
	MoveWindow(hwnd, 300, 200, WINDOWS_WIDTH + 1, WINDOWS_HEIGHT, TRUE);
	barr[0].x = 150; barr[0].y = 150; barr[0].height = 25; barr[0].wedth = 100; barr[0].identy = _TEXT("�����ѯ");
	barr[1].x = 290; barr[1].y = 150; barr[1].height = 25; barr[1].wedth = 100; barr[1].identy = _TEXT("�ͳ���ѯ");
	barr[2].x = 150; barr[2].y = 190; barr[2].height = 25; barr[2].wedth = 100; barr[2].identy = _TEXT("�ùݲ�ѯ");
	barr[3].x = 290; barr[3].y = 190; barr[3].height = 25; barr[3].wedth = 150; barr[3].identy = _TEXT("����·�߲�ѯ");
	barr[4].x = 275; barr[4].y = 230; barr[4].height = 25; barr[4].wedth = 50; barr[4].identy = _TEXT("����");
	module[3]->MyCreateBotton(hwnd, ghinstance, barr, wParam, lParam);
	return TRUE;
}