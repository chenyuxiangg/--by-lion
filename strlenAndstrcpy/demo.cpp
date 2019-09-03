#include <iostream>
#include <assert.h>
using namespace std;

int My_strlen_point(char* pch)
{
	for (int i = 0; ; i++)
	{
		if (pch[i] == '\0')
			return i;
	}
	return 0;
}

int My_strlen_arr(char charr[])
{
	int i = 0;
	while (charr[i] != '\0')
		i++;
	return i;
}

char* My_strcpy_point(char* a, const char* b)
{
	//需考虑重新存储的字符数组的大小
	assert(a != NULL && b != NULL);
	int i = 0;
	int j = 0;
	while ((a[i++] = b[j++]) != '\0');
	return a;
}

char* My_strcpy_arr(char a[], const char b[])
{
	assert(a != NULL && b != NULL);
	int i = 0;
	int j = 0;
	while ((a[i++] = b[j++]) != '\0');
	return a;
}

int main(int argc, char* argv[])
{
	char a[5] = { 0 };
	char b[4];
	memset(b, 'a', sizeof(b)-1);
	b[sizeof(b) - 1] = '\0';
	//cout << "My_strlen_arr:" << My_strlen_arr(b) << endl;
	//cout << "My_strlen_point:" << My_strlen_point(b) << endl;
	cout << "My_strcpy_arr:" << My_strcpy_arr(a,b) << endl;
	//cout << "My_strcpy_point:" << My_strcpy_point(a, b) << endl;
	//cout << "My_strlen_arr:" << My_strlen_arr(a) << endl;

	system("pause");
	return 0;
}