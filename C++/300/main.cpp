#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 使用 lower_bound
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it == res.end())
                res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};


// 二分 + 贪心
/*
class Solution {
public:
    int binary(vector<int> &res, int r, int x)
    {
        int l = 0, mid;
        while(l <= r)
        {
            mid = (l + r) >> 1;
            if(res[mid] > x)
            {
                r = mid - 1;
            }
            else if(res[mid] < x)
            {
                l = mid + 1;
            }
            else{
                return mid;
            }
        }
        return l;
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        vector<int> res(nums.size(), INT_MIN);
        int ans = 0;
        res[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > res[ans])
            {
                res[++ans] = nums[i];
            }
            else
            {
                res[binary(res, ans, nums[i])] = nums[i];
            }
        }
        return ans + 1;
    }
};
*/
// dp dp[i]表示前i个数以nums[i]结尾的最长上升子序列
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
*/


int main()
{
    Solution s;
    vector<int> nums = {3, 1, 2, 6, 4, 5, 10, 7};
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}
