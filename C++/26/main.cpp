#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(auto num : nums)
        {
            if(!i && num > nums[i-1])
            {
                nums[i++] = num;
            }
        }
        return i;
    }
};


/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == nums[i-1])
                count++;
            else
                nums[i-count] = nums[i];
        }
        return nums.size() - count;
    }
};
*/

int main()
{

    return 0;
}
