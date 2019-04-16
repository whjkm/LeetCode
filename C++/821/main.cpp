#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
using namespace std;
class Solution{
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.length(),pos = -n;
        vector<int> res(n,n);
        for(int i=0; i<n; i++){
            if(S[i] == C) pos = i;
            res[i] = min(res[i], abs(i - pos));
        }
        for(int i=n-1; i>=0; i--){
            if(S[i] == C) pos = i;
            res[i] = min(res[i], abs(i-pos));
        }
        return res;
    }
};
/*class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.length();
        vector<int> res(n,n);
        for(int i=0; i<n; i++){
            if(S[i] == C)
                res[i] = 0;
        }
        for(int i=1; i<n; i++){
            res[i] = min(res[i], res[i-1]+1);
        }
        for(int i=n-2; i>=0; i--){
            res[i] = min(res[i], res[i+1]+1);
        }
        return res;
    }
};
*/
int main()
{
    Solution s;
    vector<int> res;
    string S = "loveleetcode";
    char C = 'e';
    res = s.shortestToChar(S,C);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}
