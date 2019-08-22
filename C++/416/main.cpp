#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum >> 2;
        vector<vector<int>> dp(n+1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i < n + 1; ++i)
        {
            dp[i][0] = 1;
        }
        for(int j = 1; j < target + 1; ++j)
        {
            dp[0][j] = 0;
        }
        for(int i = 1; i < n + 1; ++i)
        {
            for(int j = 1; j < target + 1; ++j)
            {
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1])
                {
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
                }
            }
        }
       return dp[n][target];
    }
};
/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() <= 1) return false;
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        int small = nums[start++], big = nums[end--];
        cout << small << " " << big << endl;
        while(start <= end)
        {
            if(small < big)
            {
                small += nums[start++];
                cout << small << " " << big << endl;
            }
            else if(small > big)
            {
                big += nums[end--];
                cout << small << " " << big << endl;
            }
            if(small == big && start <= end)
            {
                small += nums[start++];
            }
        }
        cout << small << " " << big << endl;
        if(small == big && start >= end)
        {
            return true;
        }
        return false;
    }
};
*/

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,5};
    cout << s.canPartition(nums) << endl;
    return 0;
}
