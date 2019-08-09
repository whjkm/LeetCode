#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//ֻ��Ҫ��ͬһ��DFS��ʱ��������Ԫ���Ƿ���ͬ,
//�������ͬԪ����ͬһ�㿪ʼDFS�Ϳ���

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
                continue;    // ȥ��,��ͬԪ�صڶ�������DFSʱֱ������
            combination.push_back(candidates[i]);
            dfs(target - candidates[i], i + 1, candidates, combination, res);
            combination.pop_back();
        }
    }
};

// ���԰�
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
            cout << "��ǰ�������ǣ�start:" << start << " " << "target:" << target<< " "<< "i:" << i <<endl;
            if(i && candidates[i] == candidates[i-1] && i > start)
            {
                cout << "ȥ��" << endl;
                continue;    // ȥ��,��ͬԪ�صڶ�������DFSʱֱ������
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
