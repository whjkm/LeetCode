#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    //������һ����������������������е�ֵ
    // Divide and Conquer �����㷨����ÿ�����ֵ����ֵ
    int maxSubArray2(vector<int>& nums) {
        maxSub(nums, 0, nums.size()-1);
    }

    int maxSub(vector<int>& nums, int l, int r){
        if(l > r){
            return INT_MIN;
        }
        int m = l + (r - l)/2;
        int lmax = maxSub(nums, l, m-1);
        int rmax = maxSub(nums, m+1, r);
        int ml = 0, mr = 0;
        for(int i = m-1, sum = 0; i >= l; i--){
            sum += nums[i];
            ml = max(ml, sum);
        }
        for(int i = m+1, sum = 0; i <= r; i++){
            sum += nums[i];
            mr = max(mr, sum);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }

    //DP, �ҵ���ǰ״̬��ǰһ��״̬֮��Ĺ�ϵ
    int maxSubArray1(vector<int>& nums) {
        int dp[nums.size()], maxSum;
        dp[0] = maxSum = nums[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }

    //Kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int curSum, maxSum;
        curSum = maxSum = nums[0];
        for(int i=1; i < nums.size(); i++){
            curSum = max(nums[i], curSum + nums[i]);
            maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums({-2,1,-3,4,-1,2,1,-5,4});
    Solution s;
    cout << s.maxSubArray2(nums) << endl;
    return 0;
}
