#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 还是异或，出现两次的一个字母
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for(int i = 0; i < s.size(); ++i)
            res ^= s[i];
        for(int i = 0; i < t.size(); ++i)
            res ^= t[i];
        return res;
    }
};
//map
/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> mymap;
        for(int i = 0; i < s.length(); ++i)
            mymap[s[i]]++;
        for(int i = 0; i < t.length(); ++i)
            mymap[t[i]]++;
        map<char, int>::iterator it;
        char res;
        for(it = mymap.begin(); it != mymap.end(); ++it)
        {
            if(it->second % 2 != 0)
                res = it->first;
        }
        return res;
    }
};
*/

int main()
{
    Solution s;
    string s1 = "abcd";
    string s2 = "abcde";
    cout << s.findTheDifference(s1, s2) << endl;
    return 0;
}
