#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 转置3次
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
// 利用数组去储存
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i < nums.size(); ++i)
        {
            nums[(i+k)%n] = res[i];
        }
    }
};
*/
int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    Solution s;
    s.rotate(nums, 3);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << endl;
    }
    return 0;
}
