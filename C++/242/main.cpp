#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// 用数组模拟
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hashmap[26] = {0};
        if(s.size() != t.size())
           return false;
        for(int i = 0; i < s.size(); ++i)
        {
            hashmap[s[i] - 'a'] ++;
            hashmap[t[i] - 'a'] --;
        }
        for(int i = 0; i < 26; ++i)
        {
            if(hashmap[i] > 0)
                return false;
        }
        return true;
    }
};
/***
用hashmap存储每个字符出现的次数，如果两个字符串的字符出现的次数一致，返回true；
***/
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        if(s.size() != t.size())
           return false;
        for(int i = 0; i < s.size(); ++i)
        {
            umap[s[i]]++;
        }
        for(int i = 0; i < t.size(); ++i)
        {
            if(umap[t[i]] > 0)
                umap[t[i]]--;
        }
        for(unordered_map<char,int>::iterator it = umap.begin(); it != umap.end(); it++)
        {
            if(it -> second > 0)
                return false;
        }
        return true;
    }
};
*/

/***
思路一： 首先判断两个字符串的大小是否相等，如果不相等直接返回错误。
然后对两个字符串进行排序，比较两个字符串排序后的结果。
***/
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
           return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
*/

int main()
{
    Solution s;
    string str1 = "eat";
    string str2 = "eta";
    cout << s.isAnagram(str1, str2) << endl;
    return 0;
}
