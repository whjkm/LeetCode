#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for(int i=len-1; i >=0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            }else if(digits[i] < 9){
                digits[i]++;
                break;
            }
        }
        // 处理进位情况 一位数
        if(digits[0] == 0){
            digits[0] += 1;
            digits.push_back(0);
        }

        return digits;
    }
};

int main()
{
    int a[3] = {0};
    vector<int> digits(a, a+1);
    Solution s;
    digits = s.plusOne(digits);
    for(int i=0; i < digits.size(); i++)
    {
         printf("%d",digits[i]);
    }
    return 0;
}
