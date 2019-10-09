#include <iostream>
#include <vector>
using namespace std;

// dp i & (i-1) 减少了一个1
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i = 1; i <= num; ++i)
        {
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }
};

//暴力
/*
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        for(int i = 1; i <= num; ++i)
        {
            res.push_back(cal(i));
        }
        return res;
    }
    int cal(int n)
    {
        int sum = 0;
        while(n)
        {
            sum++;
            n = n & (n-1);
        }
        return sum;
    }
};
*/


int main()
{
    Solution s;
    vector<int> res = s.countBits(5);
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
