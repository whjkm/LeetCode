#include <iostream>
#include <vector>
using namespace std;

// 求一个最大的连续子数组  Kadane's Algorithm
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0, max_sum = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            sum = max(0, sum += prices[i]-prices[i-1]);
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};
// minPrice is the minimum price from day 0 to day i.
//And maxPro is the maximum profit we can get from day 0 to day i.
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int res = 0;
        for(int i = 0; i < prices.size(); ++i)
        {
            min_price = min(min_price, prices[i]);
            res = max(res, prices[i] - min_price);
        }
        return res;
    }
};
*/

int main()
{
    Solution s;
    vector<int> nums = {7,1,5,3,6,4};
    cout << s.maxProfit(nums) << endl;
    return 0;
}
