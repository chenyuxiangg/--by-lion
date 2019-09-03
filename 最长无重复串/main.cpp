#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int length = s.length();
		int dic[128];
		if (length == 0)
			return 0;
		int* flag = new int[length];
		for (int i = 0; i < length; ++i) {
			flag[i] = -1;
		}
		memset(dic, -1, sizeof(dic));

		for (int i = 0; i < length; ++i) {
			int index = s[i] - '\0';
			if (dic[index] == -1) {
				dic[index] = i;
			}
			else {
				flag[i] = dic[index];
				dic[index] = i;
			}
		}
		//test
		for (int i = 0; i < length; ++i) {
			cout << flag[i] << " ";
		}
		cout << endl;
		//
		int max = 0;
		int cur = 0;
		for (int i = 0; i < length; ++i) {
			for (int j = i; j < length; ++j) {
				if (flag[j] < 0) {
					cur++;
				}
				else {
					if (flag[j] < i)
						cur++;
					else {
						max = max < cur ? cur : max;
						cur = 0;
						break;
					}
				}
				if (j == length - 1) {
					max = max < cur ? cur : max;
					cur = 0;
				}
			}
		}
		delete[] flag;
		return max;
	}
};
int main(int argc, char* argv) {
	Solution solu;
	string s;
	cin >> s;
	int x = solu.lengthOfLongestSubstring(s);
	cout << x << endl;
	system("pause");
	return 0;
}