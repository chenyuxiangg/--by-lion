// chksig.cpp : Defines the entry point for the console application.
//
#include <cstdio>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void cls(HANDLE hStdOut)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	// Get the number of character cells in the current buffer. 
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD coordScreen = { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	// Fill the entire screen with blanks.
	FillConsoleOutputCharacter(hStdOut, ' ', dwConSize, coordScreen, &cCharsWritten);
	// Get the current text attribute.
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	// Set the buffer's attributes accordingly.
	FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	// Put the cursor at its home coordinates.
	SetConsoleCursorPosition(hStdOut, coordScreen);
}

void set_console_size(HANDLE hStdOut, SHORT width, SHORT height)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	// Get the number of character cells in the current buffer. 
	BOOL ok = GetConsoleScreenBufferInfo(hStdOut, &csbi);
	if (csbi.dwSize.X < csbi.srWindow.Left + width || csbi.dwSize.Y < csbi.srWindow.Top + height)
	{
		csbi.dwSize.X = csbi.srWindow.Left + width;
		csbi.dwSize.Y = csbi.srWindow.Top + height;
		ok = SetConsoleScreenBufferSize(hStdOut, csbi.dwSize);
	}
	csbi.srWindow.Bottom = csbi.srWindow.Top + height - 1;
	csbi.srWindow.Right = csbi.srWindow.Left + width - 1;
	ok = SetConsoleWindowInfo(hStdOut, TRUE, &csbi.srWindow);
	csbi.dwSize.X = csbi.srWindow.Left + width;
	csbi.dwSize.Y = csbi.srWindow.Top + height;
	ok = SetConsoleScreenBufferSize(hStdOut, csbi.dwSize);
}

enum
{
	BLACK = 0,
	DARKBLUE = FOREGROUND_BLUE,
	DARKGREEN = FOREGROUND_GREEN,
	DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
	DARKRED = FOREGROUND_RED,
	DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
	DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	GRAY = FOREGROUND_INTENSITY,
	BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
	GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
	YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};


enum status_t
{
	status_exit = -1,
	status_welcome = 1,
	status_login,
	status_type,
	status_action,
	status_generator,
};

enum
{
	action_machine = 1,
	action_human = 2,
	type_double_chromosphere = 1,
	type_7in35 = 2
};

struct context_t
{
	status_t status;
	int delay;
	int cls;
	union
	{
		struct
		{
			short type;
			short action;
		}
		bit;
		int all;
	}event;
};

void welcome(context_t *ctx)
{
	printf("*******************************************************\n");
	printf("*                    ��ӭ�����Ʊϵͳ                  *\n");
	printf("*******************************************************\n");
	printf("\n\n\n�����������\n");
	getchar();
	ctx->status = status_login;
}

void login(context_t *ctx)
{
	char username[128];
	char password[128];
	memset(username, 0, sizeof(username));
	memset(password, 0, sizeof(password));

	ctx->status = status_exit;

	for (int retry = 3; retry > 0; --retry)
	{
		printf("�û�����");
		for (int i = 0; i < sizeof(username) - 1; i++)
		{
			char ch = getchar();
			if (ch == '\n') { break; }
			username[i] = ch;
		}
		printf("��  �룺");
		for (int i = 0; i < sizeof(password) - 1;)
		{
			char ch = _getch();
			if (ch == '\r')
			{
				break;
			}

			if (ch == '\b')
			{
				if (i > 0)
				{
					putchar('\b');
					putchar(' ');
					putchar('\b');
					i--;
				}
			}
			else
			{
				password[i] = ch;
				putchar('*');
				i++;
			}
		}
		if (strcmp(username, "123") == 0 && strcmp(password, "123") == 0)
		{
			ctx->status = status_type;
			ctx->cls = 1;
			ctx->delay = 500;
			printf("\n");
			printf("��¼�ɹ�����������˵�\n");
			return;
		}
		else
		{
			printf("\n�ʺŻ������������������\n");
		}
	}
	printf("�ʺŻ�����������������࣬ϵͳ�����˳�\n");
	ctx->status = status_exit;
	ctx->cls = 0;
	ctx->delay = 500;
}

void get_action(context_t *ctx)
{
	for (bool _stop = false; !_stop;)
	{
		printf("               *1.��ѡ*\n");
		printf("               *2.��ѡ*\n");
		printf("               *3.����*\n\n\n\n");
		printf("����������ѡ��\n");
		int type;
		scanf_s("%d", &type);
		switch (type)
		{
		case 1:
			ctx->event.bit.action = action_machine;
			_stop = true;
			break;
		case 2:
			ctx->event.bit.action = action_human;
			_stop = true;
			break;
		case 3:
			ctx->delay = 500;
			ctx->cls = 1;
			ctx->status = status_type;
			return;
		default:
			break;
		}
	}
	ctx->delay = 500;
	ctx->cls = 1;
	ctx->status = status_generator;
}

void get_type(context_t *ctx)
{
	for (bool _stop = false; !_stop;)
	{
		printf("               *1.35ѡ7 *\n");
		printf("               *2.˫ɫ��*\n");
		printf("               *3.��  ��*\n\n\n\n");
		printf("����������ѡ��\n");
		int type;
		scanf_s("%d", &type);
		switch (type)
		{
		case 1:
			ctx->event.bit.type = type_7in35;
			_stop = true;
			break;
		case 2:
			ctx->event.bit.type = type_double_chromosphere;
			_stop = true;
			break;
		case 3:
			ctx->delay = 0;
			ctx->status = status_exit;
			return;
		default:
			break;
		}
	}
	ctx->delay = 500;
	ctx->cls = 1;
	ctx->status = status_action;
}

int cmp_int(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

#define arraysize(A) (sizeof(A)/sizeof((A)[0]))

void generator(context_t *ctx)
{
	if (ctx->event.bit.type == type_7in35)
	{
		int number[7];
		if (ctx->event.bit.action == action_machine)
		{
			srand((unsigned int)time(0));
			for (int i = 0; i < arraysize(number);)
			{
				bool contain = false;
				int rd = rand() % 35;
				for (int j = 0; j < i; ++j)
				{
					if (number[j] == rd)
					{
						contain = true;
						break;
					}
				}

				if (!contain)
				{
					number[i++] = rd;
				}
			}
		}
		else
		{
			for (int i = 0; i < arraysize(number);)
			{
				bool contain = false;
				printf("������1��35֮�������(%d/7):", i + 1);
				int rd;
				scanf_s("%d", &rd);
				for (int j = 0; j < i; ++j)
				{
					if (number[j] == rd)
					{
						contain = true;
						break;
					}
				}

				if (contain)
				{
					printf("�������ظ�����\n");
				}
				else if (rd > 0 && rd < 36)
				{
					number[i++] = rd;
				}
				else
				{
					printf("�������ַ�ΧΪ1��35\n");
				}
			}
		}
		qsort(number, arraysize(number), sizeof(number[0]), cmp_int);
		for (int i = 0; i < arraysize(number); i++)
		{
			printf("%d ", number[i]);
		}
		printf("\n");
	}
	else if (ctx->event.bit.type == type_double_chromosphere)
	{
		int number[7];
		if (ctx->event.bit.action == action_machine)
		{
			srand((unsigned int)time(0));
			for (int i = 0; i < arraysize(number);)
			{
				bool contain = false;
				int mod = i == arraysize(number) - 1 ? 16 : 33;
				int rd = rand() % mod;
				for (int j = 0; j < i && i != arraysize(number) - 1; ++j)
				{
					if (number[j] == rd)
					{
						contain = true;
						break;
					}
				}
				if (!contain)
				{
					number[i++] = rd;
				}
			}
		}
		else
		{
			for (int i = 0; i < arraysize(number);)
			{
				if (i != arraysize(number) - 1)
				{
					bool contain = false;
					printf("������1��33֮�������(%d/6):", i + 1);
					int rd;
					scanf_s("%d", &rd);
					for (int j = 0; j < i; ++j)
					{
						if (number[j] == rd)
						{
							contain = true;
							break;
						}
					}

					if (contain)
					{
						printf("�������ظ�����\n");
					}
					else if (rd > 0 && rd < 34)
					{
						number[i++] = rd;
					}
					else
					{
						printf("�������ַ�ΧΪ1��33\n");
					}
				}
				else
				{
					printf("������1��16֮������� x:");
					int rd;
					scanf_s("%d", &rd);
					if (rd > 0 && rd < 17)
					{
						number[i++] = rd;
					}
					else
					{
						printf("�������ַ�ΧΪ1��33\n");
					}
				}
			}
		}
		qsort(number, arraysize(number) - 1, sizeof(number[0]), cmp_int);
		for (int i = 0; i < arraysize(number); i++)
		{
			printf("%d ", number[i]);
		}
		printf("\n");
	}
	printf("\n * * * * * * *\n");
	ctx->delay = 500;
	ctx->cls = 0;
	ctx->event.all = 0;
	ctx->status = status_type;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	//
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// change console title
	SetConsoleTitleA("��Ʊϵͳ");
	// set console background
	SetConsoleTextAttribute(hStdOut, CYAN);
	set_console_size(hStdOut, 60, 20);

	context_t ctx;
	ctx.status = status_welcome;
	ctx.delay = 0;
	ctx.cls = 0;
	ctx.event.all = 0;

	for (int _stop = 0; !_stop;)
	{
		switch (ctx.status)
		{
		case status_exit:
			_stop = 1;
			break;
		case status_welcome:
			welcome(&ctx);
			break;
		case status_login:
			login(&ctx);
			break;
		case status_type:
			get_type(&ctx);
			break;
		case status_action:
			get_action(&ctx);
			break;
		case status_generator:
			generator(&ctx);
			break;
		default:
			break;
		}
		if (ctx.delay) { Sleep(ctx.delay); }
		if (ctx.cls) { cls(hStdOut); }
	}
	printf("*�밴������˳�ϵͳ*\n");
	getchar();
	return 0;
}

