#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<bool> visited(nums.size(), false);
        DFS(subset, nums, visited);
        return res;
    }
    void DFS(vector<int> subset, vector<int>& nums, vector<bool>& visited)
    {
        if(subset.size() == nums.size())
        {
            res.push_back(subset);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(visited[i]) continue;
            if(i != 0 && nums[i] == nums[i-1] && !visited[i]) continue;
            visited[i] = true;
            subset.push_back(nums[i]);
            DFS(subset, nums, visited);
            subset.pop_back();
            visited[i] = false;
        }
    }
};

/*
using namespace std;
class Solution {
public:
    // backtrack 回溯
    //可以参考链接
    //https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        permuteRecursive(nums, 0, result);
        return result;
    }
    void permuteRecursive(vector<int> &nums, int begin, vector<vector<int>> &result){
        if(begin >= nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = begin; i < nums.size(); i++){
            swap(nums[begin], nums[i]);
            permuteRecursive(nums, begin + 1, result);
            swap(nums[begin], nums[i]);
        }
    }

    // 直接引用next_permutation方法
    vector<vector<int>> permute1(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do res.emplace_back(nums);
        while(next_permutation(nums.begin(), nums.end()));
        return res;
    }
};
*/

int main()
{
    Solution s;
    vector<int> nums({1,2,3});
    vector<vector<int>> res;
    res = s.permute(nums);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[0].size(); j++){
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
