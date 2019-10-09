#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 位运算
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++)
        {
            res = (res << 1) + (n >> i & 1);
        }
        return res;
    }
};

int main()
{

    return 0;
}
