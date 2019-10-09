#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n)
        {
            res ++;
            n = n & (n-1);
        }
        return res;
    }
};
// 位运算
/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; ++i)
        {
            if(n >> i & 1) res++;
        }
        return res;
    }
};
*/

int main()
{
    Solution s;
    cout << s.hammingWeight(00000000000000000000000000001011) << endl;
    return 0;
}
