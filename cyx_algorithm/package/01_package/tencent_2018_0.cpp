/*
链接：https://www.nowcoder.com/questionTerminal/f3ab6fe72af34b71a2fd1d83304cbbb3
来源：牛客网

题目：
小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，现在小Q想用这些歌组成一个总长度正好为K的歌单，每首歌最多只能在歌单中出现一次，在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。

描述：
输入：
每个输入包含一个测试用例。
每个测试用例的第一行包含一个整数，表示歌单的总长度K(1<=K<=1000)。
接下来的一行包含四个正整数，分别表示歌的第一种长度A(A<=10)和数量X(X<=100)以及歌的第二种长度B(B<=10)和数量Y(Y<=100)。保证A不等于B。

输出：
输出一个整数,表示组成歌单的方法取模。因为答案可能会很大,输出对1000000007取模的结果。

示例：
输入：
5
2 3 3 3

输出：
9
*/

//解法一：
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
//看成01背包问题
//define:dp[i][j]:=从前i首歌中取出总长度不超过j的总方法数
//对于：dp[i][j] = (dp[i-1][j]%mod + dp[i-1][j-len[i]]%mod)%mod;
//理解为：从前i首歌中取出总长度不超过j的总方法数的计算有两种可能
/*
1、不取第i首歌，那么方法数就等于dp[i-1][j]%mod;
2、取第i首歌，那么方法数就是dp[i-1][j-len[i]]%mod;
这两种情况互斥，因此用加号连接。
*/
int main(int argc,char* argv[]){
    int k,x,a,b,y;
    cin >> k;
    cin >> a >> x >> b >> y;
    
    int len[201];//取数组大小比两类歌总数多一是因为len[0]需要为0
    int dp[201][1001];
    memset(len,0,sizeof(len));
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
   for(int i = 1; i <= x;++i){
       len[i] = a;
   }
    for(int j = x+1;j <= x + y;++j){
        len[j] = b;
    }
    
    for(int i = 1;i <= x+y;++i){
        for(int j = 0;j <= k;++j){
            if(j < len[i]){
                dp[i][j] = dp[i-1][j]%mod;
            }
            else{
                dp[i][j] = (dp[i-1][j]%mod + dp[i-1][j-len[i]]%mod)%mod;
            }
        }
    }
    cout << dp[x+y][k];
}

//解法二：
/*

*/
