/*
实际例子：构造回文子序列（结合回文串的特点）
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 1001;
int maxlen[MAX][MAX];

int LCS(string s1,string s2){
    int length1 = s1.size();
    int length2 = s2.size();
    //初始化，也就是当字符串为空串时与任意长度的字符串的公共子串都是0
    for(int i = 0;i < length1;++i){
        matrix[i][0] = 0;
    }
    for(int i = 0;i < length2;++i){
        matrix[0][i] = 0;
    }
    for(int i = 1;i <= length1;++i){
        for(int j = 1;j <= length2;++j){
            if(s1[i-1] == s2[j-1]){
                matrix[i][j] = matrix[i-1][j-1] + 1;
            }
            else{
                matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
            }
        }
    }
    return matrix[length1][length2];
}
