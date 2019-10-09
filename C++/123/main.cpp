#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 有限状态机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;
        for(int i = 1; i < n; ++i)
        {
            s1 = max(s1, -prices[i]);     // 第一次买入价格
            s2 = max(s2, s1+prices[i]);   // 第一次卖出价格
            s3 = max(s3, s2-prices[i]);
            s4 = max(s4, s3+prices[i]);
        }
        return max(0,s4);
    }
};

//dp dp[k,i] = max(dp[k,i-1], dp[i]-dp[j]+dp[k-1,j-1])
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(3, vector<int>(n, 0));
        for(int k = 1; k <= 2; ++k)
        {
           int minx = prices[0];
           for(int i = 1; i < n; ++i)
           {
               minx = min(minx, prices[i] - dp[k-1][i-1]);
               dp[k][i] = max(dp[k][i-1], prices[i] - minx);
           }
        }
        return dp[2][n-1];
    }
};
*/

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(3, vector<int>(n, 0));
        int maxpro = 0;
        for(int k = 1; k <=2; ++k)
        {
            int tmpmax = dp[k-1][0] - prices[0];
            for(int i = 1; i < n; ++i)
            {
                dp[k][i] = max(dp[k][i-1], tmpmax+prices[i]);
                tmpmax = max(tmpmax, dp[k-1][i] - prices[i]);
                maxpro = max(dp[k][i],maxpro);
            }
        }
        return maxpro;
    }
};
*/

//dp dp[k,i] = max(dp[k,i-1], dp[i]-dp[j]+dp[k-1,j-1])
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(3, vector<int>(n, 0));
        for(int k = 1; k <= 2; ++k)
        {
            for(int i = 1; i < n; ++i)
            {
                int minx = prices[0];
                for(int j = 1; j <= i; ++j)
                {
                    minx = min(minx, prices[j] - dp[k-1][j-1]);
                }
                dp[k][i] = max(dp[k][i-1], prices[i] - minx);
            }
        }
        return dp[2][n-1];
    }
};
*/
int main()
{

    return 0;
}
