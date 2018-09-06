#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mymap;
        for(int i=0; i < nums.size(); i++){
            if(mymap.count(target - nums[i]))
                return {mymap.find(target - nums[i])->second, i};
            mymap.insert({nums[i],i});
        }
    }
};

int main()
{
    int a[4] = {2,7,11,15};
    vector<int> nums(a,a+4);
    vector<int> r;
    int target = 9;
    Solution s;
    r = s.twoSum(nums,target);
    int len = r.size();
    for(int i=0; i<len; i++){
        printf("%d ",r[i]);
    }
    return 0;
}
