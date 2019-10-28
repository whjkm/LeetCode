#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int u = 0, d = n - 1, l = 0, r = n - 1;
        int k = 1;
        while(1)
        {
            // l -> r
            for(int col = l; col <= r; ++col)
            {
                res[u][col] = k++;
            }
            if(++u > d) break;
            // u -> d
            for(int row = u; row <= d; ++row)
            {
                res[row][r] = k++;
            }
            if(--r < l) break;
            // r -> l
            for(int col = r; col >= l; --col)
            {
                res[d][col] = k++;
            }
            if(--d < u) break;
            // d -> u
            for(int row = d; row >= u; --row)
            {
                res[row][l] = k++;
            }
            if(++l > r) break;
        }
        return res;
    }
};


int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<vector<int>> res;
    res = s.generateMatrix(n);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
