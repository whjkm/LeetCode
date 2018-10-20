#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:

    // 公式
    int climbStairs2(int n){
        return (pow((1 + sqrt(5)) / 2, n + 1) - pow((1 - sqrt(5)) / 2, n + 1)) / sqrt(5);
    }

    // 斐波拉契数列
    int climbStairs1(int n){
        if(n == 1){
            return 1;
        }
        int first = 1;
        int second = 2;
        for(int i=3; i<=n; i++){
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }


    int climbStairs(int n) {
        vector<int> res{1,1};
        for(int i=2; i<n; i++){
            res.push_back(res[i-1] + res[i-2]);
        }
        return res[n-1] + res[n-2];
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs2(4) <<endl;
    return 0;
}
