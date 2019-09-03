#pragma once
bool Quicksort(int* iarr, int i_n, int low, int hight)
{
	int origin = low;
	int temp;
	if (low > hight)//��һ���Ĵ��ڣ�ȷ����һ��while�в���Ҫlow >= 0 && hight < i_n
		return true;
	while (low != hight)
	{
		while (low < hight && iarr[hight] >= iarr[origin])//��һ��������while (low < hight && iarr[low] <= iarr[origin])
			                                              //                  low++��֮ǰ
			hight--;
		while (low < hight && iarr[low] <= iarr[origin])
			low++;
		temp = iarr[hight];
		iarr[hight] = iarr[low];
		iarr[low] = temp;
	}
	temp = iarr[origin];
	iarr[origin] = iarr[low];
	iarr[low] = temp;
	low = origin;

	Quicksort(iarr, i_n, low, hight - 1);
	Quicksort(iarr, i_n, hight + 1, i_n - 1);

	return true;
}