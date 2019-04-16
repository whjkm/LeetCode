#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
class Solution{
public:
    int longestMountain(vector<int>& A) {
        int res = 0, down = 0, up = 0;
        for(int i=1; i<A.size(); i++){
            if(down && A[i] > A[i-1] || A[i-1] == A[i])
                up = down = 0;
            down += A[i-1] > A[i];
            up += A[i] > A[i-1];
            if(down && up)
                res = max(res, down + up + 1);
        }
        return res;
    }
};

/*
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size(), res = 0;
        vector<int> up(n,0),down(n,0);
        for(int i=0; i < n; i++){
            if(i > 0 && A[i] > A[i-1]) up[i] = up[i-1] + 1;
        }
        for(int i=n-2; i>=0; i--){
            if(A[i] > A[i+1]) down[i] = down[i+1] + 1;
            if(down[i] && up[i])
                res = max(res, down[i] + up[i] + 1);
        }
        return res;
    }
};

class Solution{
public:
    int longestMountain(vector<int>& A) {
        int n = A.size(), down = 0 ,up = 0, res = 0;
        while(up < n-1){
            while(up < n-1 && A[up] >= A[up+1]){
                up++;
            }
            down = up;
            while(down<n-1 && A[down] < A[down+1]){
                down++;
            }
            while(down<n-1 && A[down] > A[down+1]){
                down++;
                res = max(res, down - up + 1);
            }
            up = down;
        }
        return res;
    }
};

*/

int main()
{
    Solution s;
    int a[11] = {0,1,2,3,4,5,4,3,2,1,0};
    vector<int> moutain(a,a+11);
    int res = s.longestMountain(moutain);
    cout << res <<endl;
    return 0;
}
