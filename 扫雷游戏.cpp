#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char * argv[])
{
	int arr[10][10] = { 0 };//�����������洢10*10 = 100�����ӵ�,���Ҷ������е�ͼ��û����
	int row, col;//ѭ������
	int count = 0;//ͳ�Ƶ��׵�����
	srand(time(NULL));//���������

	do 
	{
		row = rand() % 10;
		col = rand() % 10;//�����д���������ɵ��ף����в�ȷ��λ���Լ���ȷ��������
		if(arr[row][col] == 0)
		{
			arr[row][col] = -1;//���Ϊ�е���
			count++;
		}
	} while (count < 10);//��0-9����10�����ף��п��ܲ���������10������Ϊ����������غ�

	for(row = 0;row < 10; row++)
	{
		for (col = 0; col <= 9; col++)
		{
			if (arr[row][col] != -1)
				printf("o\t");
			else
				printf("x\t");
		}
		printf("\n\n");
	}
	return 0;
}