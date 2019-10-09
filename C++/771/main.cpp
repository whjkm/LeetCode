#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 利用集合去查找
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> res(J.begin(), J.end());
        int sum = 0;
        for(auto s : S)
        {
            if(res.count(s)) sum++;
        }
        return sum;
    }
};


//暴力枚举
/*
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for(int i = 0; i < S.size(); ++i)
        {
            for(int j = 0; j < J.size(); ++j)
            {
                if(J[j] == S[i])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
*/

int main()
{
    Solution s;
    string s1 = "aA";
    string s2 = "aAAbbbb";
    cout << s.numJewelsInStones(s1, s2) << endl;
    return 0;
}
