#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int fib(int N) {
        int fn = 0;
        int f0 = 0, f1 = 1;
        if(N == 1) return f1;
        for(int i = 2; i <= N; ++i)
        {
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
        return fn;
    }
};

int main()
{
    Solution s;
    cout << s.fib(4) << endl;
    return 0;
}
