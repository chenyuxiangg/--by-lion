#ifndef STRCOMPARE_H
#define STRCOMPARE_H
#pragma once
#include <string>
bool StrCompare(char* a, char* b)
{
	int al = strlen(a);
	int bl = strlen(b);
	if (al != bl)
		return false;
	else
	{
		for (int i = 0; i < al; i++)
			if (a[i] != b[i])
				return false;
		return true;
	}
}
#endif
