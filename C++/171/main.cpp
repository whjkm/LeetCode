#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

class Solution {
public:
    //当成26进制数处理
    int titleToNumber(string s) {
       int len = s.length();
       int sum = 0;
       for(int i=0; i < len; i++){
           sum = sum + pow(26, len - i -1) * ((int)s[i] - 64);   //用ASCII码处理
       }
       return sum;
    }
};

int main()
{
    string s = "ZY";
    Solution res;
    cout << res.titleToNumber(s) << endl;
    return 0;
}
