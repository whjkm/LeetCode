#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


/***
Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
Find the largest index l > k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array nums[k + 1:].
***/

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size(), k, l;
        if(n < 1) return ;
        for(k = n - 2; k >= 0; --k)
        {
            if(nums[k] < nums[k + 1])
                break;
        }
        if(k < 0)
            reverse(nums.begin(), nums.end());
        else
        {
            for(l = n - 1; l > k; --l)
            {
                if(nums[k] < nums[l])
                    break;
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

// next_permutationµÄÊ¹ÓÃ
/*
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0)
            return ;
        if(next_permutation(nums.begin(), nums.end()))
        {

        }
        else{
            sort(nums.begin(), nums.end());
        }
    }
};
*/

int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    s.nextPermutation(nums);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << endl;
    }
    return 0;
}
