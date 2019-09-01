#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main(int argc, char* argv[])
{
	string str;
	cin >> str;
	auto strb = find(str.cbegin(), str.cend(), '/');
	if (strb != str.cend())
	{
		strb += 2;
	}
	auto stre = find(strb, str.cend(), '/');
	for (auto it = strb; it != stre; ++it)
	{
		cout << *it;
	}
	cout << endl;

	system("pause");
	return 0;
}
