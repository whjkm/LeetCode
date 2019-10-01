#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount+1, Max);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(int j = 0; j < coins.size(); ++j)
            {
                if(i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        if(dp[amount] == Max)
            return -1;
        else
            return dp[amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1,2,5};
    cout << s.coinChange(coins, 11) << endl;
    return 0;
}
