#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/***
01交替：
    000101010
  ^ 000001010
  = 000100000
***/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^= n/4) & (n-1));
    }
};


/***
01交替：
    000101010
  ^ 000010101
  = 000111111
***/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^= n/2) & n+1);
    }
};


// 位运算
/*
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int d = n & 1;    // n的最后一位
        while((n&1) == d)
        {
            d = 1 - d;    // 交替,是否为0，1交替
            n >>= 1;      // 将n右移，判断最后一位
        }
        return n == 0;
    }
};
*/

int main()
{

    return 0;
}
