#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> candidates = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> combination;
        dfs(k, n, 0, res, combination);
        return res;
    }
    void dfs(int k, int n, int start, vector<vector<int>> &res, vector<int> &combination)
    {
        if(n == 0 && combination.size() == k)
        {
            res.push_back(combination);
            return ;
        }
        for(int i = start; i < candidates.size() && n >= candidates[i]; ++i)
        {
            combination.push_back(candidates[i]);
            dfs(k, n-candidates[i], i+1, res, combination);
            combination.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res;
    res = s.combinationSum3(3, 9);
    for(int i=0; i<res.size(); ++i)
        for(int j=0; j<res[i].size(); ++j)
        cout << res[i][j] << " ";
    return 0;
}
