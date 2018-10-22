#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
class Solution {
public:

    //按照顺时针方向，逐层遍历，注意结束条件
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())  return{};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiral(m*n);
        int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
        while(true){
            //UP
            for(int col = l; col <= r; col++){
                spiral[k++] = matrix[u][col];
            }
            if(++u > d) break;

            //Right
            for(int row = u; row <= d; row++){
                spiral[k++] = matrix[row][r];
            }
            if(--r < l) break;

            //Down
            for(int col = r ; col >= l; col--){
                spiral[k++] = matrix[d][col];
            }
            if(--d < u) break;

            //Left
            for(int row = d; row >= u; row--){
                spiral[k++] = matrix[row][l];
            }
            if(++l > r) break;
        }
        return spiral;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;
    vector<int> temp;
    int test;
    for(int i=0; i<3; i++){
        temp.clear();
        for(int j=0; j<3; j++){
            cin >> test;
            temp.push_back(test);
        }
        matrix.push_back(temp);
    }
    vector<int> res;
    res = s.spiralOrder(matrix);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}
