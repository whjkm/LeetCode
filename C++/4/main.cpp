#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
class Solution
{
public:
     double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if(m > n)
        {
            return findMedianSortedArrays2(nums2, nums1);
        }
        int l = 0, r = m, mid1, mid2, maxl, minr;
        while(l <= r)
        {
            mid1 = (l + r) >> 1;
            //mid1 = (l ^ r) + ((l & r) << 1);
            mid2 = ((m + n + 1) >> 1) - mid1;
            if(mid1 > 0 && nums1[mid1-1] > nums2[mid2])
            {
                r = mid1 - 1;
            }
            else if(mid1 < m && nums1[mid1] < nums2[mid2-1])
            {
                l = mid1 + 1;
            }
            else
            {
                if(mid1 == 0)
                {
                    maxl = nums2[mid2-1];
                }
                else if(mid2 == 0)
                {
                    maxl = nums1[mid1-1];
                }
                else
                {
                    maxl = max(nums1[mid1-1], nums2[mid2-1]);
                }

                if((m+n)%2 == 1)
                    return maxl;

                if(mid1 == m)
                {
                    minr = nums2[mid2];
                }
                else if(mid2 == n)
                {
                    minr = nums1[mid1];
                }
                else
                {
                    minr = min(nums1[mid1], nums2[mid2]);
                }
                return (maxl + minr) / 2.0;
            }
        }
        return -1;
    }
};

/*
class Solution
{
public:
    //��λ���Ķ��壬�����ڶ��ֲ��ҵ�˼����л���
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if(m > n)
        {
            return findMedianSortedArrays2(nums2, nums1);
        }
        int l = 0, r = m, mid1, mid2, maxl, minr;
        while(l <= r)
        {
            mid1 = (l ^ r) + ((l & r) << 1);    //��һ������Ļ���λ��
            mid2 = ((m + n + 1) >> 1) - mid1;   //�ڶ�������Ļ���λ��
            if(mid1 > 0 && nums1[mid1-1] > nums2[mid2])
            {
                r = mid1 - 1;                 // ���ӵ�һ������Ļ���λ��
            }
            else if(mid1 < m && nums1[mid1] < nums2[mid2 - 1])
            {
                l = mid1 + 1;                 // ���ٵ�һ������Ļ���λ��
            }
            else
            {
                if(mid1 == 0)
                {
                    maxl = nums2[mid2 - 1];
                }
                else if(mid2 == 0)
                {
                    maxl = nums1[mid1 - 1];
                }
                else
                {
                    maxl = max(nums1[mid1 - 1], nums2[mid2 - 1]);
                }

                if((m + n) % 2 == 1)
                {
                    return maxl;
                }

                if(mid1 == m)
                {
                    minr = nums2[mid2];
                }
                else if(mid2 == n)
                {
                    minr = nums1[mid1];
                }
                else
                {
                    minr = min(nums1[mid1], nums2[mid2]);
                }

                return (maxl + minr) / 2.0;
            }
        }
    }
*/

/*
//�鲢���������Ӷ�ΪO(M+N)
//����д�Ĺ鲢�����ú���
double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2)
{
    std::vector<int> res;
    std::merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),std::back_inserter(res));
    double index = (res.size() - 1) / 2.0;
    return (res[floor(index)] + res[ceil(index)]) / 2.0;
}
*/

/*
//�鲢����˼�룬��������������鲢��һ�����飬Ȼ������������е���λ��
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int n = nums1.size(), m = nums2.size();
    vector<int> nums3;
    int i = 0,j = 0;
    double mid;
    while(i < n && j < m)
    {
        if(nums1[i] < nums2[j])
        {
            nums3.push_back(nums1[i]);
            i++;
        }
        else
        {
            nums3.push_back(nums2[j]);
            j++;
        }
    }
    while(i < n)
    {
        nums3.push_back(nums1[i]);
        i++;
    }
    while(j < m)
    {
        nums3.push_back(nums2[j]);
        j++;
    }
    if((n+m)%2 != 0)
    {
        mid =  nums3[(n+m)/2];
    }
    else
    {
        mid = (double)(nums3[(n+m)/2-1] + nums3[(n+m)/2]) / 2.0;
    }
    return mid;
}
};
*/


int main()
{
    Solution s;
    int a[2] = {1,3};
    int b[2] = {2,4};
    vector<int> nums1(a,a+2);
    vector<int> nums2(b,b+2);
    cout << s.findMedianSortedArrays2(nums1,nums2) << endl;
    return 0;
}
