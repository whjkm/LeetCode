#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        long long cur = 1;
        k = k - 1;
        while(k > 0){
            int steps = caldistance(n, cur, cur+1);
            if(steps <= k){
                cur += 1;
                k -= steps;
            }else{
                cur *= 10;
                k -= 1;
            }
        }
        return cur;
    }

    int caldistance(int n,long long n1, long long n2){
        int steps = 0;
        while(n1 <= n){
            steps += min((long long)(n+1), n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};


/*
class Solution{
public:
    int findKthNumber(int n, int k) {
        int result = 1;
        k = k-1;
        while(k > 0){
            int count = 0;
            for(long long first = static_cast<long long> (result), last = first + 1;
                first <= n;
                first *= 10, last *= 10)
                {
                    count += static_cast<int>((min(n + 1LL, last)-first));
                }
                if(k >= count){
                    result += 1;
                    k -= count;
                }else{
                    result *= 10;
                    k -= 1;
                }
    }
    return result;
    }
};
*/

int main()
{
    int n, k;
    Solution s;
    cin >> n >> k;
    cout << s.findKthNumber(n,k) << endl;
    return 0;
}
