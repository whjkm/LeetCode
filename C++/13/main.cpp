#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

    //用字典存储
    int romanToInt2(string s) {
        map<char,int> mymap;
        mymap['M'] = 1000;
        mymap['D'] = 500;
        mymap['C'] = 100;
        mymap['L'] = 50;
        mymap['X'] = 10;
        mymap['V'] = 5;
        mymap['I'] = 1;
        int res = 0;
        for(int i=0; i<int(s.length()); i++){
            if(mymap[s[i-1]] < mymap[s[i]]){
                res = res + mymap[s[i]] - 2*mymap[s[i-1]];
                continue;
            }
            res += mymap[s[i]];
        }
        return res;
    }

    //倒序处理，出现比前一位数字大的情况就相减
    int convert(char c){
        if(c=='I')return 1;
        if(c=='V')return 5;
        if(c=='X')return 10;
        if(c=='L')return 50;
        if(c=='C')return 100;
        if(c=='D')return 500;
        if(c=='M')return 1000;
    }
    //倒序处理，记录当前位置和前一个位置的值
    int romanToInt1(string s) {
        int len = s.size(),res = 0;
        int pre = convert(s[len-1]);
        res += pre;
        for(int i = len-2; i>=0; i--){
            int cur = convert(s[i]);
            res += (cur >= pre)? cur : -cur;  //比当前小，减去前一个数值
            pre = cur;
        }
        return res;
    }


    //1A,逻辑语句写的有点多，按照题意给的6种情况，依次相加
    int romanToInt(string s) {
        int res = 0;
        for(int i=0; i!=s.size(); i++){
            if(s[i] == 'M'){
                res += 1000;
            }else if(s[i] == 'D'){
                res += 500;
            }else if(s[i] == 'C'){
                if(s[i+1] && s[i+1] =='D'){
                    res += 400;
                    i++;
                }else if(s[i+1] && s[i+1] =='M'){
                    res += 900;
                    i++;
                }else{
                    res += 100;
                }
            }else if(s[i] == 'L'){
                res += 50;
            }else if(s[i] == 'X'){
                if(s[i+1] && s[i+1] =='L'){
                    res += 40;
                    i++;
                }else if(s[i+1] && s[i+1] =='C'){
                    res += 90;
                    i++;
                }else{
                    res += 10;
                }
            }else if(s[i] == 'V'){
                res += 5;
            }else if(s[i] == 'I'){
                if(s[i+1] && s[i+1] =='V'){
                    res += 4;
                    i++;
                }else if(s[i+1] && s[i+1] =='X'){
                    res += 9;
                    i++;
                }else{
                    res += 1;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = "MCMXCIV";
    cout << s.romanToInt2(str) << endl;
    return 0;
}
