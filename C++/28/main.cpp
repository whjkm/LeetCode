#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 字符串匹配，暴力匹配
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for(int i = 0; i <= n-m; ++i)
        {
            int j = 0;
            for(;j < m; ++j)
            {
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j == m)
                return i;
        }
        return -1;
    }
};
/*
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) != string::npos)
        {
            return haystack.find(needle);
        }
        else
        {
            return -1;
        }
    }
};
*/

int main()
{
    string str1 = "hello";
    string str2 = "ll";
    Solution s;
    cout << s.strStr(str1, str2) << endl;
    return 0;
}
