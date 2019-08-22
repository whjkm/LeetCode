#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 贪心，尽可能多的去剪3
class Solution {
public:
    int integerBreak(int n) {
        if(n < 2) return 0;
        if(n == 2) return 1;
        if(n == 3) return 2;

        int timeof3 = n / 3;
        if(n - timeof3 * 3 == 1)
            timeof3 -= 1;
        int timeof2 = (n - timeof3 * 3) / 2;
        return (int)pow(3, timeof3) * (int)pow(2, timeof2);
    }
};
/*
class Solution {
public:
    int integerBreak(int n) {
        if(n < 2) return 0;
        if(n == 2) return 1;
        if(n == 3) return 2;
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for(int i = 4; i <= n; ++i)
        {
            for(int j = 1; j <= i/2; ++j)
            {
               dp[i] = max(dp[i], dp[j] * dp[i-j]);
            }
        }
        return dp[n];
    }
};
*/


/***
动态规划： f(n)表示把长度为n的绳子剪成若干段长度乘积的最大值
f(n) = max(f(i)* f(i-j)), 剪成i 和i-j 两部分，自下往上计算。
***/
/*
class Solution {
public:
    int integerBreak(int n) {
        if(n < 2) return 0;
        if(n == 2) return 1;
        if(n == 3) return 2;
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        int max = 0;
        for(int i = 4; i <= n; ++i)
        {
            max = 0;
            for(int j = 1; j <= i/2; ++j)
            {
                dp[i] = dp[j] * dp[i - j];
                if(dp[i] > max)
                {
                    max = dp[i];
                }
                dp[i] = max;
            }
        }
        max = dp[n];
        return max;
    }
};
*/
int main()
{
    Solution s;
    cout << s.integerBreak(10) << endl;
    return 0;
}
