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
        while(tail >=0 && s[tail] == ' ') tail--;   //ȥ��ǰ���ո�
        while(tail >=0 && s[tail] != ' '){   //����������һ������
            len++;
            tail--;
        }
        return len;
    }


    /*
    int lengthOfLastWord(string s) {
        string buf;
        stringstream str(s);    //���ַ����Կո�ֿ�
        int len = 0;
        while(str >> buf){
            len = buf.length();   //���һ���ַ����ĳ���
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
