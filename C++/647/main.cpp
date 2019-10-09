#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 中心扩散
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        for(int i = 0; i <= 2*n -1; ++i)
        {
            int left = i / 2;
            int right = left + i % 2;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                res++;
                left--;
                right++;
            }
        }
        return res;
    }
};

// dp
/*
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n <= 1) return 1;
        vector<vector<int>> dp(n, vector<int>(n,0));
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
            res++;
            if(s[i] == s[i+1] && i != n-1)
            {
                dp[i][i+1] = 1;
                res++;
            }
        }
        for(int i = 3; i <= n; ++i)
        {
            for(int j = 0; j + i -1 < n; ++j)
            {
                int k = j+i-1;
                if(s[j] == s[k] && dp[j+1][k-1] == 1)
                {
                    dp[j][k] = 1;
                    res++;
                }
            }
        }
        return res;
    }
};
*/


// 暴力
/*
class Solution {
public:
    bool judge(string s)
    {
        int i = 0, j = s.size() - 1;
        while(i <= j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        if(n <= 1) return 1;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j <= s.substr(i).size(); ++j)
            {
                string temp = s.substr(i, j);
                if(judge(temp)) res++;
            }
        }
        return res;
    }
};
*/

int main()
{
    Solution sol;
    cout << sol.countSubstrings("abc") << endl;
    return 0;
}
