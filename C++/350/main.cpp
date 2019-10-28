#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 排序，类似二分，双指针
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] > nums2[j])
            {
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
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
    res = s.intersect(nums1, nums2);
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
