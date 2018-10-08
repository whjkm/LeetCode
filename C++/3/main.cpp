#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
    /*
    int lengthOfLongestSubstring(string s) {
        int m[256] = {0}, res = 0, left = 0;
        for(int i=0; i < s.size(); i++){
            if(m[s[i]] == 0 || m[s[i]] < left){
                res = max(res, i-left+1);
            }else{
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }
    */

    int lengthOfLongestSubstring(string s) {
        vector<int> m(256, -1);
        int res = 0, left = -1;
        for(int i=0; i<s.size(); i++){
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i-left);
        }
        return res;
    }
};
int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}
