//c选则排序
void selection_sort(int arr[],int len)
{
	int i, j, min, temp;
	for(i = 0;i < len -1;i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
			if (arr[min] > arr[j])
				min = j;
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

//c++选择排序
//整数或浮点型都可用，若要使用物件（class），必须设定 > 的运算子
template<typename T>
void selection_sort(T arr[],int len)
{
	int i, j, min;
	for(i = 0;i < len -1;i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
			if (arr[min] > arr[j])
				min = j;
		swap(arr[i], arr[min]);
	}
}