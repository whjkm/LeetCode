#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, tail = s.length() - 1;
        while(tail >=0 && s[tail] == ' ') tail--;   //去除前导空格
        while(tail >=0 && s[tail] != ' '){   //倒序遍历最后一个单词
            len++;
            tail--;
        }
        return len;
    }


    /*
    int lengthOfLastWord(string s) {
        string buf;
        stringstream str(s);    //将字符串以空格分开
        int len = 0;
        while(str >> buf){
            len = buf.length();   //最后一个字符串的长度
        }
        return len;
    }*/


};

int main()
{
    Solution s;
    cout << s.lengthOfLastWord("b   a    ") <<endl;
    return 0;
}
