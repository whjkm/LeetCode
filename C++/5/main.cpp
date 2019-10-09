#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

//中心扩散
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        int start = 0, maxlen = 0;
        for(int i = 1; i < n; ++i)
        {
            //寻找以i-1,i为中点偶数长度的回文
            int low = i-1, high = i;
            while(low >= 0 && high < n && s[low] == s[high])
            {
                low --;
                high ++;
            }
            if(high - low - 1 > maxlen)
            {
                maxlen = high - low - 1;
                start = low + 1;
            }

            //寻找以i为中心的奇数长度的回文
            low = i-1, high = i+1;
            while(low >=0 && high < n && s[low] == s[high])
            {
                low --;
                high ++;
            }
            if(high - low - 1 > maxlen)
            {
                maxlen = high - low - 1;
                start = low + 1;
            }
        }
        return s.substr(start, maxlen);
    }
};

// dp记录子串是否是回文串
/*
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        vector<vector<int>> dp(n, vector<int>(n,0));
        int start = 0, ends = 1;
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;    // 一个字母的情况
            if(s[i] == s[i+1] && i != n-1)  // 两个字母相等的情况
            {
                dp[i][i+1] = 1;
                start = i;
                ends = 2;
            }
        }
        for(int i = 3; i <= n; ++i)  // 子串的长度
        {
            for(int j = 0; j + i - 1 < n; ++j)
            {
                int k = j + i -1;
                if(s[j] == s[k] && dp[j+1][k-1] == 1)
                {
                    dp[j][k] = 1;
                    start = j;
                    ends = i;
                }
            }
        }
        return s.substr(start,ends);
    }
};
*/

// 暴力求解 o（n3）
/*
class Solution {
public:
    bool judge(string s)
    {
        int i = 0, j = s.size()-1;
        while(i < j)
        {
            if(s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        vector<string> res;
        for(int i = 0; i < s.size(); ++i)
        {
            for(int j = 1; j <= s.substr(i).size(); ++j)
            {
                string temp = s.substr(i, j);
                if(judge(temp)) res.push_back(temp);
            }
        }
        int max_len = 0, index = 0;
        for(int i = 0; i < res.size(); ++i)
        {
            if(max_len < res[i].size())
            {
                max_len = res[i].size();
                index = i;
            }
        }
        return res[index];
    }
};
*/


int main()
{
    Solution s;
    cout << s.longestPalindrome("cbbd") << endl;
    return 0;
}
