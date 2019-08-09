#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// »ØËÝ·¨
class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        dfs(target, 0, candidates, combination, res);
        return res;
    }
    void dfs(int target, int start, vector<int>& candidates, vector<int> &combination, vector<vector<int>> &res)
    {
        if(!target)
        {
            res.push_back(combination);
            return ;
        }
        for(int i = start; i != candidates.size() && target >= candidates[i]; ++i)
        {
            combination.push_back(candidates[i]);
            dfs(target - candidates[i], i, candidates, combination, res);
            combination.pop_back();
        }
    }
};

/*
class Solution{
public:
    void dfs(int target, vector<int>& candidates, int start, vector<int> temp, vector<vector<int>> &res)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return ;
        }
        for(int i = start; i < candidates.size(); ++i)
        {
            if(i !=0 && candidates[i] == candidates[i-1]) continue;
            int n = target - candidates[i];
            if(n >= 0)
            {
                temp.push_back(candidates[i]);
                dfs(n, candidates, i, temp, res);
                temp.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(target, candidates, 0, temp, res);
        return res;
    }

};
*/

/*
class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    int nums_len;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return res;
        nums_len = candidates.size();
        dfs(0, 0, target, candidates);
        return res;
    }
    void dfs(int start, int sum, int target, vector<int> candidates)
    {
        if(sum == target){
            res.push_back(ans);
            return ;
        }
        else if(sum > target)
            return ;
        else
        {
            for(int i = start; i < nums_len; ++i)
            {
                ans.push_back(candidates[i]);
                dfs(i, sum + candidates[i], target, candidates);
                ans.pop_back();
            }
        }
    }
};
*/

int main()
{
    Solution s;
    vector<int> data = {2,3,5};
    int target = 8;
    vector<vector<int>> res;
    res = s.combinationSum(data, target);
    for(int i = 0; i < res.size(); ++i)
        for(int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    return 0;
}
