#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
class Solution {
public:
    /*
     * clockwise rotate
     * first reverse up to down, then swap the symmetry
     * 1 2 3     7 8 9     7 4 1
     * 4 5 6  => 4 5 6  => 8 5 2
     * 7 8 9     1 2 3     9 6 3
    */
    //先将第一行和第n行互换，然后再转置
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    //直接对其中的元素进行顺时针旋转
    void rotate1(vector<vector<int>>& matrix){
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a < b){
            for(int i=0; i < (b - a); i++){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            a++;
            b--;
        }
    }

    //First we transpose the matrix and then reverse every row:
    void rotate1(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i=0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i < n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
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
    s.rotate1(matrix);
    for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                cout << matrix[i][j];
            }
            cout << endl;
        }
    return 0;
}
