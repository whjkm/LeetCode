#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:

    //简洁版
    int maxArea1(vector<int>& height) {
        int max = 0, l = 0, r = height.size() - 1;
        while(l < r){
            int area = height[l] > height[r] ? (r - l) * height[r--] : height[r] ? (r - l) * height[l++];
            if(area > max){
                max = area;
            }
        }
        return max;
    }

    //类似二分查找的思想，从两端开始遍历，更新最大面积
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_area = 0,temp = 0;
        while(l < r){
            if(height[l] > height[r]){
                temp = height[r] * (r - l);
                r--;
            }else{
                temp = height[l] * (r - l);
                l++;
            }
            if(max_area < temp){
                max_area = temp;
            }
        }
        return max_area;
    }
};

int main()
{
    Solution s;
    int a[9] = {1,8,6,2,5,4,8,3,7};
    vector<int> nums(a,a+9);
    cout << s.maxArea(nums) << endl;
    return 0;
}
