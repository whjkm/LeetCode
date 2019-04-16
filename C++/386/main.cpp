#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int cur = 1;
        for(int i=1; i<=n; i++){
            res.push_back(cur);
            if(cur * 10 <= n){
                cur *= 10;
            }else{
                if(cur >= n){
                    cur /= 10;
                }
                cur += 1;
                while(cur % 10 == 0){
                    cur /= 10;
                }
            }
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<int> nums;
    nums = s.lexicalOrder(n);
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << endl;
    }
    return 0;
}
