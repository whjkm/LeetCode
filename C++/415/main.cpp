#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length() < num2.length())
        {
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }
        int i,j;
        for(i = num1.length()-1, j = num2.length()-1; i>=0; i--, j--)
        {
            num1[i] = char(num1[i] + (j>=0 ? num2[j] - '0':0));
            if(num1[i]- '0' >= 10)
            {
                num1[i] = char((num1[i] - '0') % 10 + '0');
                if(i) num1[i-1]++;
                else
                    num1 = '1' + num1;
            }
        }
        return num1;
    }
};

int main()
{
    string s1 = "1233232";
    string s2 = "12312312";
    Solution s;
    cout << s.addStrings(s1, s2) << endl;
    return 0;
}
