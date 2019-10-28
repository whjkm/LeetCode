#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 摩尔投票算法
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1, candidate2;
        int count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == candidate1) count1++;
            else if(nums[i] == candidate2) count2++;
            else{
                if(count1 && count2) {
                    count1--;
                    count2--;
                }
                else if(count1)
                {
                    candidate2 = nums[i];
                    count2 = 1;
                }
                else
                {
                    candidate1 = nums[i];
                    count1 = 1;
                }
            }
        }
        vector<int> candidate;
        if(count1 > 0) candidate.push_back(candidate1);
        if(count2 > 0) candidate.push_back(candidate2);
        vector<int> res;
        for(int i = 0; i < candidate.size(); ++i)
        {
            int count = 0;
            for(int j = 0; j < nums.size(); ++j)
            {
                if(candidate[i] == nums[j])
                    count++;
            }
            if(count > nums.size()/3) res.push_back(candidate[i]);
        }
        return res;
    }
};

int main()
{

    return 0;
}
