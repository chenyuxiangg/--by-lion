#include<stdio.h>
#include<stdlib.h>

int main(int argc,char * argv[])
{
	int i, x, max;
	if(argc <= 1)
	{
		printf("�÷���max ��1 ��2 ~��n\n");
		exit(0);
	}

	max = atoi(argv[1]);
	for(i = 2; i < argc; i++)
	{
		x = atoi(argv[i]);
		if(x > max)
		{
			max = x;
		}
	}
	printf("������Ϊ��%d\n", max);

	return 0;
}