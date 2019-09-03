#include <iostream>
using namespace std;

void GetNext(char* pch,int next[])
{
	int c_length = strlen(pch);
	int k = -1;//ǰ׺�е�ǰ��λ��
	int j = 0;//��׺�е�ǰλ��
	next[0] = -1;//��next����ĵ�һ��λ���ֶ���Ϊ-1

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
	int pS_i = 0;//ԭ���е�ǰƥ�䵽��λ��
	int kmp_count = 0;
	int next[50];
	GetNext(pP, next);

	int jump = 0;//������
	if((pP_length != 1) && (pP[next[pP_length - 1]] == pP[pP_length - 1]))
		jump = next[pP_length - 1] + 1;

	while (pS_i < pS_length)
	{
		int pP_i = 0;//ģʽ���е�ǰƥ�䵽��λ��

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