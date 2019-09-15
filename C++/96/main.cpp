#include <iostream>
#include <vector>
using namespace std;

// 卡特兰数
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 0, k = i - 1; j <= i - 1; ++j, --k)
            {
                dp[i] += dp[j]*dp[k];
            }
        }
        return dp[n];
    }
};

// catanla 数的通项公式计算
class Solution {
public:
    int numTrees(int n) {
        long long ans = 1;
        for(int i = n + 1; i <= 2 * n; ++i)
        {
            ans = ans * i/(i-n);
        }
        return ans / (n + 1);
    }
};



int main()
{
    Solution s;
    cout << s.numTrees(4) << endl;
    return 0;
}
