#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//按照标准输出
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        for(int i = 0; i <= nums.size(); ++i)
        {
            DFS(nums, temp, 0, i);
        }
        return res;
    }
    void DFS(vector<int>& nums, vector<int>& temp, int index, int n)
    {
        if(n < 0)
            return ;
        if(n == 0) res.push_back(temp);
        else{
            for(int i = index; i < nums.size(); ++i)
            {
                if(i > index && nums[i] == nums[i-1]) continue;
                temp.push_back(nums[i]);
                DFS(nums, temp, i + 1, n - 1);
                temp.pop_back();
            }
        }
    }
};


/*
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        DFS(nums, 0, temp);
        return res;
    }
    void DFS(vector<int>& nums, int index, vector<int>& temp)
    {
        res.push_back(temp);
        for(int i = index; i < nums.size(); ++i)
        {
            if(i > index && nums[i] == nums[i-1]) continue;
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
    vector<int> nums = {1,2,2};
    vector<vector<int>> res;
    res = s.subsetsWithDup(nums);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << endl;
        }
    }
    return 0;
}


