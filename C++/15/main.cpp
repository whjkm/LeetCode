#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    //threeSum transfer twoSum : a + b = -c
    //有点类似于快排的思想
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = nums[i] * -1;
            int s = i+1, e = n-1;
            while(s < e){
                if(nums[s] + nums[e] == target){
                    vector<int> temp({nums[i], nums[s], nums[e]});
                    result.push_back(temp);
                    s = s + 1;
                    while(s < e && nums[s] == nums[s-1]){
                        s = s + 1;
                    }
                }else if(nums[s] + nums[e] < target){
                    s = s + 1;
                }else{
                    e = e - 1;
                }
            }
        }
        return result;
    }
};


int main()
{
    Solution s;
    int a[6] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(a, a+6);
    vector<vector<int>> result;
    result = s.threeSum(nums);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << endl;
        }
    }
    return 0;
}
