#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	map<char, char*> table;
	table['a'] = "*-"; table['b'] = "-***"; table['c'] = "-*-*"; table['d'] = "-**"; table['e'] = "*";
	table['f'] = "**-*"; table['g'] = "--*"; table['h'] = "****"; table['i'] = "**"; table['j'] = "*---";
	table['k'] = "-*-"; table['l'] = "*-**"; table['m'] = "--"; table['n'] = "-*"; table['o'] = "---";
	table['p'] = "*--*"; table['q'] = "--*-"; table['r'] = "*-*"; table['s'] = "***"; table['t'] = "-";
	table['u'] = "**-"; table['v'] = "***-"; table['w'] = "*--"; table['x'] = "-**-"; table['y'] = "-*--";
	table['z'] = "--**";

	string str;
	getline(cin, str);

	auto str_it = str.cbegin();
	for (str_it; str_it != str.cend(); ++str_it)
	{
		if (*str_it == ' ')
			cout << endl;
		else if (isalpha(*str_it))
		{
			if (*str_it >= 'A' && *str_it <= 'Z')
				cout << table[*str_it + 32] << " ";
			else
				cout << table[*str_it] << " ";
		}
		else
			continue;
	}
	cout << endl;

	system("pause");
	return 0;

}
