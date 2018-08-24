#include <iostream>

//二进制加法 https://blog.csdn.net/gaoyubo_taili/article/details/79694729

class Solution{
public:
    int getSum(int a, int b){
        int sum = 0;
        while(b != 0)
        {
            sum = a ^ b;         //对a,b进行异或操作,不进位加法
            b = (a & b) << 1;           //进位加法
            a = sum;
        }
        return sum;
    }
};
using namespace std;

int main()
{
    Solution s;
    cout << s.getSum(4,6) << endl;
    return 0;
}
