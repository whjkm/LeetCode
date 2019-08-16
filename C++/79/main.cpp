#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/***
DFS:数据量大，传入参数不加&,就会爆内存
***/

class Solution {
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int rows, cols;
vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        if(rows == 0) return false;
        cols = board[0].size();
        int flag = false;
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for(int row = 0; row < board.size(); ++row)
        {
            for(int col = 0; col < board[row].size(); ++col)
            {
                flag = DFS(board, word, row, col, 0);
                if(flag == true)
                   return true;
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>> &board, string &word, int row, int col, int index)
    {
        if(index == word.size() - 1)
            return board[row][col] == word[index];
        if(board[row][col] == word[index])
        {
            visited[row][col] = true;
            // 向四个方向搜索
            for(int i = 0; i < 4; ++i)
            {
                int x = row + direction[i][0];
                int y = col + direction[i][1];
                if(x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y])
                {
                    if(DFS(board, word, x, y, index + 1))
                        return true;
                }
            }
            //四个方向都没找到，回溯
            visited[row][col] = false;
        }
        return false;
    }
};


int main()
{

    return 0;
}
