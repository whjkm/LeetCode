#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/***
˼·���ȼ����ܹ�С������ı����-�ص����
S = С��������� * 6 - �ص��� * 2��
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
                    num += grid[i][j];     // ����������
                }
                if(grid[i][j] > 1)
                {
                    dup = dup + grid[i][j] - 1;  // һ��λ�����ж����������ظ�����
                }
                if(i + 1 < grid[0].size() && grid[i+1][j] != 0)
                {
                    dup += min(grid[i][j], grid[i+1][j]);  // �·����ص�
                }

                if(j + 1 < grid.size() && grid[i][j+1] != 0)
                {
                    dup += min(grid[i][j], grid[i][j+1]);  // �������ص�
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
