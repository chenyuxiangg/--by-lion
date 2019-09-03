#include <iostream>
using namespace std;

void GetNext(char* pch,int next[])
{
	int c_length = strlen(pch);
	int k = -1;//前缀中当前的位置
	int j = 0;//后缀中当前位置
	next[0] = -1;//将next数组的第一个位置手动置为-1

	while(j < c_length - 1)
	{
		if (k == -1 || pch[k] == pch[j])
		{
			++k;
			++j;

			next[j] = k;
		}
		else
			k = next[k];
	}
}

int KMP(char* pS,char* pP)
{
	int pS_length = strlen(pS);
	int pP_length = strlen(pP);
	int pS_i = 0;//原串中当前匹配到的位置
	int kmp_count = 0;
	int next[50];
	GetNext(pP, next);

	int jump = 0;//回溯量
	if((pP_length != 1) && (pP[next[pP_length - 1]] == pP[pP_length - 1]))
		jump = next[pP_length - 1] + 1;

	while (pS_i < pS_length)
	{
		int pP_i = 0;//模式串中当前匹配到的位置

		while (pS_i < pS_length && pP_i < pP_length)
		{
			if (pP_i == -1 || pS[pS_i] == pP[pP_i])
			{
				++pP_i;
				++pS_i;
			}
			else
			{
				pP_i = next[pP_i];
			}
		}

		if (pP_i == pP_length)
		{
			kmp_count++;
			pS_i -= jump;
		}
		else
			return kmp_count;
	}
	return kmp_count;
}

int main(int argc,char* argv[])
{
	char S[50];
	char P[50];

	cin >> S;
	cin >> P;

	cout << KMP(S, P) << endl;

	system("pause");
	return 0;
}