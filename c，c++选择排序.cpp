//cѡ������
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

//c++ѡ������
//�����򸡵��Ͷ����ã���Ҫʹ�������class���������趨 > ��������
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