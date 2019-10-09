#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        int res = 1, max_len = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i-1])
            {
                res++;
            }
            else
            {
                res = 1;
            }
            max_len = max(max_len, res);
        }
        return max_len;
    }
};

int main()
{
    vector<int> nums = {1,3,5,4,7};
    Solution s;
    cout << s.findLengthOfLCIS(nums) << endl;
    return 0;
}
