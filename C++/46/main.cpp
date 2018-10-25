#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

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
