#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    /*
    string reverseString(string s) {
        string str;
        int len = s.length();
        for(int i=len-1; i>=0; i--){
            str += s[i];
        }
        return str;
    }
    */
    /*
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
    */

    char *reverseString(char *s) {
        strrev(s);
        return s;
    }
};

int main()
{
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    //string res = s.reverseString(str);
    char ch[50] = "A man, a plan, a canal: Panama";
    char *temp = s.reverseString(ch);
    cout << temp <<endl;
    //cout << res <<endl;
    return 0;
}
