#pragma once
bool Quicksort(int* iarr, int i_n, int low, int hight)
{
	int origin = low;
	int temp;
	if (low > hight)//这一步的存在，确保下一步while中不需要low >= 0 && hight < i_n
		return true;
	while (low != hight)
	{
		while (low < hight && iarr[hight] >= iarr[origin])//这一步必须在while (low < hight && iarr[low] <= iarr[origin])
			                                              //                  low++；之前
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