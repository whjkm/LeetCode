#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
class Solution{
public:
    int singleNumber(vector<int>& nums){
        for(int i=1; i<nums.size(); i++){
             nums[0] ^= nums[i];    // 利用异或运算
        }
        return nums[0];
    }
};


int main()
{
    int a[5] = {4,1,2,1,2};
    vector<int> nums(a, a+5);
    Solution s;
    printf("%d\n", s.singleNumber(nums));
    return 0;
}
