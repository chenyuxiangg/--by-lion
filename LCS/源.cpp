/*最长公共子串*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> LCS(const string& s1, const string& s2) {
	string longer = (s1.size() > s2.size() ? s1 : s2);
	string shorter = (s1.size() < s2.size() ? s1 : s2);
	int llen = longer.size();
	int slen = shorter.size();
	int maxlen = 0;
	vector<string> res;
	int** lcs = NULL;
	lcs = new int*[llen];
	for (int i = 0; i < llen; ++i) {
		lcs[i] = new int[slen];
	}

	for (int i = 0; i < llen; ++i) {
		for (int j = 0; j < slen; ++j) {
			if (longer[i] == shorter[j]) {
				if (i == 0 || j == 0) {
					lcs[i][j] = 1;
				}
				else {
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				}
				if (lcs[i][j] > maxlen) {
					maxlen = lcs[i][j];
					res.erase(res.begin(), res.end());
					string tmp = longer.substr(i - maxlen+1, maxlen);
					res.push_back(tmp);
				}
				else if (lcs[i][j] == maxlen) {
					res.push_back(longer.substr(i - maxlen+1, maxlen));
				}
			}
			else {
				lcs[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < llen; ++i) {
		delete[] lcs[i];
	}
	delete[] lcs;
	return res;
}

int main(int argc, char* argv[]) {
	string s1, s2;
	cin >> s1 >> s2;
	vector<string> res = LCS(s1, s2);
	int len = res.size();
	for (int i = 0; i < len; ++i) {
		cout << res[i] << endl;
	}
	system("pause");
	return 0;
}