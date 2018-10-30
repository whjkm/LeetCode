#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
class Solution {
public:

    // 筛选法
    int countPrimes(int n) {
        vector<int> res(n+1,0);
        for(int i = 2; i <= sqrt(n) + 1; i++){
            for(int j = 2; j <= n/i; j++){
                res[i*j] = 1;
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(res[i] == 0){
                count++;
            }
        }
        return count;
    }

    // 奇数筛选法
    int countPrimes1(int n) {
        if (n <= 2) return 0;
        vector<bool> res(n, false);
        int count = 1;
        int upper = sqrt(n);
        for(int i = 3; i < n; i += 2){  //奇数筛选
            if(!res[i]){
                count++;
                if(i > upper)
                    continue;
                for(int j = i*i; j < n; j += i){
                    res[j] = true;
                }
            }
        }
        return count;
    }


    int countPrimes2(int n) {
        vector<bool> res(n, false);
        res[0] = res[1] = true;
        for(int i = 2; i < sqrt(n); i++){
            if(!res[i]){
                for(int j = i*i; j < n; j += i){
                    res[j] = true;
                }
            }
        }
        return count(res.begin(),res.end(),false);
    }
};

int main()
{
    Solution s;
    cout << s.countPrimes2(10) <<endl;
    return 0;
}
