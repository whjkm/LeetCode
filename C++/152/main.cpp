#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//Calculate prefix product in A.
//Calculate suffix product in A.
//Return the max.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int l = 0, r = 0, res = 0;
        for(int i = 0; i < n; ++i)
        {
            l = (l ? l:1)*nums[i];
            r = (r ? r:1)*nums[n-i-1];
            res = max(res, max(l, r));
        }
        return res;
    }
};

// 负数变号，保存最小的数和最大的数
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       if(nums.size() == 1) return nums[0];
       int max_pro = 1, min_pro = 1;
       int res = 0;
       for(auto num : nums)
       {
           if(num < 0)
             swap(max_pro, min_pro);
           max_pro = max(max_pro*num, num);
           min_pro = min(min_pro*num, num);
           res = max(max_pro, res);
       }
       return res;
    }
};
*/

int main()
{
    vector<int> nums = {2,3,-2,4};
    Solution s;
    cout << s.maxProduct(nums) << endl;
    return 0;
}
