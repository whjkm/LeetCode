#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        set<int>::iterator it;
        for(it = st1.begin(); it != st1.end(); ++it)
        {
            if(st2.count(*it))
                res.push_back(*it);
        }
        return res;
    }
};
int main()
{
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> res;
    Solution s;
    res = s.intersection(nums1, nums2);
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
