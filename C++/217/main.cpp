#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(st.count(nums[i]))
                return true;
            st.insert(nums[i]);
        }
        return false;
    }
};
// 排序
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};
8/

// 利用set去重
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        int m = st.size();
        if(n == m)
            return false;
        return true;
    }
};
*/

int main()
{
    vector<int> nums = {1,2,3,1};
    Solution s;
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}
