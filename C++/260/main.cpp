#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// 异或运算
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            diff ^= nums[i];
        }
        diff &= -diff;     // 从右到左第一个为1的位，异或得到的两个数，一个为0，一个为1
        vector<int> res(2,0);
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] & diff)
            {
                res[0] ^= nums[i];
            }
            else
            {
                res[1] ^= nums[i];
            }
        }
        return res;
    }
};

// 排序
/*
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums[0] != nums[1]) res.push_back(nums[0]);
        if(nums[n-2] != nums[n-1]) res.push_back(nums[n-1]);
        for(int i = 1; i < n-1; ++i)
        {
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
                res.push_back(nums[i]);
        }
        return res;
    }
};
*/
// map
/*
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> mymap;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
            mymap[nums[i]]++;
        map<int, int>::iterator it;
        for(it = mymap.begin(); it != mymap.end(); ++it)
        {
            if(it->second == 1)
                res.push_back(it->first);
        }
        return res;
    }
};
*/


int main()
{

    return 0;
}
