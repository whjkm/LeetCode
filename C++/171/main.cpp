#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

class Solution {
public:
    //����26����������
    int titleToNumber(string s) {
       int len = s.length();
       int sum = 0;
       for(int i=0; i < len; i++){
           sum = sum + pow(26, len - i -1) * ((int)s[i] - 64);   //��ASCII�봦��
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
