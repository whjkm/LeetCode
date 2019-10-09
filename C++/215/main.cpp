#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size() ==0 || nums.size() < k || k <= 0) return -1;
        for(int i = 0; i < k; ++i)
        {
            res.push_back(nums[i]);
        }
        for(int i = k / 2 - 1; i >= 0; i--)
        {
            adjustHeap(res, i, k);
        }
        for(int i = k; i < nums.size(); i++)
        {
            if(nums[i] > res[0])
            {
                res[0] = nums[i];
                adjustHeap(res, 0, k);
            }
        }
        return res[0];
    }
private:
    void adjustHeap(vector<int>& nums, int i, int length)
    {
        int temp = nums[i], j;
        for(j = 2 * i + 1; j < length; j = 2 * j + 1)
        {
            if(j < length && j+1 <length && nums[j] > nums[j+1])
                ++j;
            if(temp <= nums[j])
                break;
            nums[i] = nums[j];
            i = j;
        }
        nums[i] = temp;
    }
};

int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    Solution s;
    cout << s.findKthLargest(nums, 3) << endl;
    return 0;
}
