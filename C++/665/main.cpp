#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    bool checkPossibility(vector<int>& nums){
        int len = nums.size(), count = 0;
        for(int i=0; i < len-1; i++){
            if(nums[i] > nums[i+1]){
                count++;
                if(count > 1){
                    return false;
                }
                if(i > 0 && nums[i+1] < nums[i-1]){
                    nums[i+1] = nums[i];
                }
                else{
                    nums[i] = nums[i+1];
                }

            }
        }
        return true;
    }
};


int main()
{
    Solution s;
    vector<int> nums;
    int a,res;
    while(cin >> a){
        nums.push_back(a);
        if(cin.get() == '\n'){
            break;
        }
    }
    res = s.checkPossibility(nums);
    cout << res << endl;
    return 0;
}
