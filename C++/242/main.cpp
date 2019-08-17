#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// ������ģ��
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
��hashmap�洢ÿ���ַ����ֵĴ�������������ַ������ַ����ֵĴ���һ�£�����true��
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
˼·һ�� �����ж������ַ����Ĵ�С�Ƿ���ȣ���������ֱ�ӷ��ش���
Ȼ��������ַ����������򣬱Ƚ������ַ��������Ľ����
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
