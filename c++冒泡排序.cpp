//普通冒泡,将大的数往后沉，小的数上浮
void bubble_sort(int arr[],int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = 1; j < len - i; j++)
		{
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
}
/*
优化改进：
在某次遍历中如果没有数据交换，说明整个数组已经有序，若初时序列就是排好的，
如果用基础的冒泡排序方法，人然还要比较O（N^2）次，但无交换次数


改进思路：
通过设置标志位来记录此次遍历有无数据交换，进而可以判断是否要继续循环，设置一
个flag标记，当在一趟序列中没有发生交换，则该序列已排好，但优化后的时间复杂的
没有发生量级的改变。
*/

//改进程序
void bubble_sort(int arr[],int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		bool exchange = true;
		for (int j = len - 1; j > i; j--)//为甚么j > i?    因为i是外循环次数，每执行一次外循环，就有一个数拍好，内循环就可以
										 //少比较一次
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			exchange = false;
		}
		if (exchange)
			return;
	}
}


/*
改进二：
如果有100个数的数组，仅前10个无序，后面的都已排好且都大于前10个
，那么在第一趟遍历后，最后发生交换的位置必定小于10，且这个位置之后的数据必定有序。

改进思路：
记录某次遍历时最后发生数据交换的位置pos，这个位置之后的数据已经有序，因此通过记录最后
发生数据交换的位置就的以确定下次循环的范围了。由于pos位置之后的记录均以交换到位，故在
下一趟排序时只要扫描到pos位置即可。
*/

void bubble_sort(int arr[],int len)
{
	int j, k;
	int flag = len;

	while(flag > 0)
	{
		k = flag;
		flag = 0;
		for(j = 1;j < k;j++)//由于k位置之后的数据都已排好，所以j只用遍历到k就行
			if(arr[j -1] > arr[j])
			{
				swap(arr[j - 1], arr[j]);
				flag = j;
			}
	}
}
