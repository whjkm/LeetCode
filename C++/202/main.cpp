#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Floyd Cycle detection algorithm
    // ���������ɻ�����Happy Number�Ļ����ǲ����ܴ���1��
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do{
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        }while(slow != fast);    //�ж��Ƿ��л�
        if(slow == 1) return true;
        else return false;
    }

    // ��ƽ����
    int digitSquareSum(int n){
        int sum = 0, tmp;
        while(n){
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    // Using hashtable
    bool isHappy1(int n) {
        int num = 0;
        unordered_map<int, bool> table;
        table[n] = 1;
        while(n != 1){
            while(n){
                num += (n % 10) * (n % 10);
                n /= 10;
            }
            if(table[num]) break;   //�Ѿ�����
            else table[num] = 1;    //���뼯��
            n = num;
            num = 0;
        }
        return 1 == n;
    }

    // Brent's Cycle detection algorithm
    bool isHappy2(int n) {
        int slow = n;
        int fast = digitSquareSum(n);
        int cnt = 1;
        int lim = 2;
        while(slow != fast){
            if(cnt == lim){  //time to start a new power of two?
                cnt = 1;
                lim = lim * 2;
                slow = fast;   // ����
            }
            else
                cnt++;

            fast = digitSquareSum(fast);
        }
        return fast == 1;
    }

};
int main()
{
    Solution s;
    cout << s.isHappy2(20) << endl;
    return 0;
}



