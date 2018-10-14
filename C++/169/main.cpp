#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:

    //����Ԫ�ؽ��м������������ͬ��Ԫ�ؽ����ۼӣ����ǵ�ǰԪ�ؾͽ�������һ
    //����������ٵ�0�����滻��ǰ����Ԫ��
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

    //�����и�������ͬԪ�ص�������������鳤�ȵ�һ��
    //ֱ�Ӷ�Ԫ�ؽ�����������м���Ǹ�Ԫ��
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
