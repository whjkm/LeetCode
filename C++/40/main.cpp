#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//只需要在同一层DFS的时候检查相邻元素是否相同,
//避免从相同元素在同一层开始DFS就可以

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        dfs(target, 0, candidates, combination, res);
        return res;
    }
    void dfs(int target, int start, vector<int>& candidates, vector<int>& combination, vector<vector<int>>& res)
    {
        if(!target)
        {
            res.push_back(combination);
            return ;
        }
        for(int i = start; i < candidates.size() && target >= candidates[i]; ++i)
        {
            if(i && candidates[i] == candidates[i-1] && i > start)
                continue;    // 去重,相同元素第二个进行DFS时直接跳过
            combination.push_back(candidates[i]);
            dfs(target - candidates[i], i + 1, candidates, combination, res);
            combination.pop_back();
        }
    }
};

// 调试版
/*
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        dfs(target, 0, candidates, combination, res);
        return res;
    }
    void dfs(int target, int start, vector<int>& candidates, vector<int>& combination, vector<vector<int>>& res)
    {
        if(!target)
        {
            res.push_back(combination);
            return ;
        }
        for(int i = start; i < candidates.size() && target >= candidates[i]; ++i)
        {
            cout << "当前的索引是：start:" << start << " " << "target:" << target<< " "<< "i:" << i <<endl;
            if(i && candidates[i] == candidates[i-1] && i > start)
            {
                cout << "去重" << endl;
                continue;    // 去重,相同元素第二个进行DFS时直接跳过
            }

            cout << "candi:" << candidates[i] << endl;
            combination.push_back(candidates[i]);
            cout << "com:";
            for(int i = 0; i < combination.size(); ++i)
               cout << combination[i] << " ";
            cout << endl;
            dfs(target - candidates[i], i + 1, candidates, combination, res);
            combination.pop_back();
        }
    }
};
*/
int main()
{
    Solution s;
    vector<int> data = {1,5,1};
    int target = 6;
    vector<vector<int>> res;
    res = s.combinationSum2(data, target);
    for(int i = 0; i < res.size(); ++i)
        for(int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    return 0;
}
