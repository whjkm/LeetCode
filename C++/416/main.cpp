#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 01�����������е�Ԫ���ܷ�����sum/2�ı�����
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int target = sum / 2;
        if(*max_element(nums.begin(), nums.end()) > target) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = 1;
        for(auto num : nums)
        {
            for(int i = target; i >= 1; --i)
            {
                if(dp[i - num])
                {
                    dp[i] = true;
                    if(dp[target] == true)
                        return true;
                }

            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,5,11,5};
    cout << s.canPartition(nums) << endl;
    return 0;
}
