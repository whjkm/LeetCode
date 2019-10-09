#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 位运算
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return !(n & (n-1));
    }
};

int main()
{
    Solution s;
    cout << s.isPowerOfTwo(-16) << endl;
    return 0;
}
