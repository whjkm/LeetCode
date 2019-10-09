#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// dp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<vector<int>> dp(k+1, vector<int>(n,0));
        for(int i = 1; i <= k; ++i)
        {
            int minx = prices[0];
            for(int j = 1; j < n; ++j)
            {
                minx = min(minx, prices[j] - dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j-1], prices[j] - minx);
            }
        }
        return dp[k][n-1];
    }
};


int main()
{

    return 0;
}
