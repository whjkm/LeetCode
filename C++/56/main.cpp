#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() < 1) return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(res.back().back() < intervals[i].front())
            {
                res.push_back(intervals[i]);
            }
            else{
                res.back().back() = max(res.back().back(), intervals[i].back());
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res;
    res = s.merge(intervals);
    for(auto & tmp : res)
    {
        for(auto & i : tmp)
        {
            cout << i << endl;
        }
    }
    return 0;
}
