#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/***
思路；先计算总共小立方体的表面积-重叠面积
S = 小立方体个数 * 6 - 重叠块 * 2；
***/
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum = 0, num = 0, dup = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] != 0)
                {
                    num += grid[i][j];     // 立方体总数
                }
                if(grid[i][j] > 1)
                {
                    dup = dup + grid[i][j] - 1;  // 一个位置上有多个立方体的重复数量
                }
                if(i + 1 < grid[0].size() && grid[i+1][j] != 0)
                {
                    dup += min(grid[i][j], grid[i+1][j]);  // 下方有重叠
                }

                if(j + 1 < grid.size() && grid[i][j+1] != 0)
                {
                    dup += min(grid[i][j], grid[i][j+1]);  // 右面有重叠
                }
            }
        }
        sum = num * 6 - dup * 2;
        return sum;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{2,1},{1,1}};
    cout << s.surfaceArea(grid) << endl;
    return 0;
}
