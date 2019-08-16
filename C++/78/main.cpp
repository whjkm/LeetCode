#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for(auto& num : nums)
        {
            int n = subs.size();
            for(int i = 0; i < n; ++i)
            {
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};

// 回溯
/*
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> temp;
        for(int i = 0; i <= nums.size(); ++i)
        {
             DFS(nums, 0, temp, i);   // 标准输出
        }
        return res;
    }
    void DFS(vector<int>& nums, int index, vector<int> &temp, int n)
    {
        if(n < 0) return ;
        if(n == 0) res.push_back(temp);
        else{
            for(int i = index; i < nums.size(); ++i)
            {
                temp.push_back(nums[i]);
                DFS(nums, i + 1, temp, n - 1);
                temp.pop_back();
            }
        }
    }
};
*/
/*
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() < 1) return res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        DFS(nums, 0, temp);
        return res;
    }

    void DFS(vector<int>& nums, int index, vector<int> &temp)
    {
        res.push_back(temp);
        for(int i = index; i < nums.size(); ++i)
        {
            if(i != index && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            DFS(nums, i + 1, temp);
            temp.pop_back();
        }
    }
};
*/

int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res;
    res = s.subsets(nums);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << endl;
        }
    }
    return 0;
}
