#include <stdio.h>
#include <malloc.h>
int main(void)
{
	int * p;
	int len;
	int i;

	//构建动态一维数组
	printf("请输入想要的长度：\n");
	scanf_s("%d", &len);
	p = (int *)malloc(4 * len);

	//操作动态一维数组
	for (i = 0; i < len; i++)
	{		scanf_s("%d", &p[i]);
}
	//输出动态一维数组
	printf("数据输出：\n");
	for (i = 0; i < len; i++)
		printf("%d\n", p[i]);
	return 0;

}