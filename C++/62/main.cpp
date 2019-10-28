#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 滚动数组，滚动优化
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};


// dp[i][j] 表示i,j位置的路径数,
// dp[i][j]只能由dp[i-1][j],dp[i][j-1]位置得来。
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,1));
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
*/

int main()
{
    Solution s;
    cout << s.uniquePaths(3,7) << endl;
    return 0;
}
