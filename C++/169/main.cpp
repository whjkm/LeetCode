#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:

    //对主元素进行计数，如果是相同的元素进行累加，不是当前元素就将个数减一
    //如果计数减少到0，就替换当前的主元素
    int majorityElement1(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) {
            return nums[0];
        }
        int temp = nums[0], count = 0;
        for(int i = 1; i != nums.size(); i++){
            if(temp == nums[i]){
                ++count ;
            }else{
                --count;
            }
            if(count == 0){
                temp = nums[i];
                count = 0;
            }
        }
        return temp;
    }

    //题意中给出的相同元素的数量会大于数组长度的一半
    //直接对元素进行排序，输出中间的那个元素
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }

};
int main()
{
    Solution s;
    int num[7] = {2,2,1,1,1,2,2};
    vector<int> a(num, num+3);
    cout << s.majorityElement(a) << endl;
    return 0;
}
