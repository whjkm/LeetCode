#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366] = {};
        int n = days.size();
        for(auto day : days)
            dp[day] = costs[0];
        for(int i = 1; i <= days[n-1]; ++i)
        {
            if(!dp[i])
                dp[i] = dp[i-1];
            else
            {
                dp[i] = min(dp[i-1] + costs[0],min(dp[max(0,i-7)] + costs[1],
                              dp[max(0,i-30)] + costs[2]));
            }
        }
        return dp[days[n-1]];
    }
};

// 按照一年的天数进行计算，没有出行的天数的开销==上一次出行的开销
/*
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(days.begin(), days.end());
        int dp[366] = {};
        dp[0] = 0;
        for(int i = 1; i < 366; i++)
        {
            if(travel.find(i) == travel.end())
                dp[i] = dp[i-1];
            else
            {
                dp[i] = min(dp[max(0,i-1)] + costs[0],
                              min(dp[max(0,i-7)] + costs[1],
                              dp[max(0,i-30)] + costs[2]));
            }
        }
        return dp[365];
    }
};
*/

int main()
{
    Solution s;
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    cout << s.mincostTickets(days, costs) << endl;
    return 0;
}
