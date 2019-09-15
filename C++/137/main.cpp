#include <iostream>
#include <vector>
using namespace std;

// 转化为2进制处理，按照32位，依次处理每一位上的0,1个数。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int len = nums.size();
       int res = 0;
       for(int i = 0; i < 32; ++i)
       {
           int count = 0;
           int bit = 1 << i;
           for(int j = 0; j < len; ++j)
           {
               if(nums[j] & bit)
                  count ++;
           }
           if(count % 3)
               res |= bit;
       }
       return res;
    }
};
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto num : nums)
        {
            b = b ^ num & ~a;
            a = a ^ num & ~b;
        }
        return b;
    }
};
*/
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int a = 0, b = 0;
       for(int i = 0; i < nums.size(); ++i)
       {
          int tempa = (a & ~b & ~nums[i]) + (~a & b & nums[i]);
          b = (~a & ~b & nums[i]) + (~a & b & ~nums[i]);
          a = tempa;
       }
       return b;
    }
};
*/
int main()
{
    Solution s;
    vector<int> nums = {2,2,3,2};
    cout << s.singleNumber(nums) << endl;
    return 0;
}
