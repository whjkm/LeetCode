#include <iostream>

//�����Ƽӷ� https://blog.csdn.net/gaoyubo_taili/article/details/79694729

class Solution{
public:
    int getSum(int a, int b){
        int sum = 0;
        while(b != 0)
        {
            sum = a ^ b;         //��a,b����������,����λ�ӷ�
            b = (a & b) << 1;           //��λ�ӷ�
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
