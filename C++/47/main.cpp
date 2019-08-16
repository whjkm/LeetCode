#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        DFS(temp, nums, visited);
        return res;
    }
    void DFS(vector<int>& temp, vector<int>& nums, vector<bool>& visited)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(visited[i])  continue;
            if(i != 0 && nums[i] == nums[i-1] && !visited[i - 1]) continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            DFS(temp, nums, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res;
    vector<int> nums = {1,1,2};
    res = s.permuteUnique(nums);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << endl;
        }
    }
    return 0;
}
