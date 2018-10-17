class Solution:

    # 中位数的定义，用来划分一个数组
    # 对较短的数组进行二分查找
    def findMedianSortedArrays1(self, A, B):
        m, n = len(A), len(B)
        if m > n:
            A, B, m, n = B, A, n, m
        if n == 0:
            raise ValueError

        imin, imax, half_len = 0, m, (m + n + 1) // 2
        while imin <= imax:
            i = (imin + imax) // 2
            j = half_len - i
            if i < m and B[j-1] > A[i]:
                imin = i + 1           # i 需要增大
            elif i > 0 and A[i-1] > B[j]:
                imax = i - 1           # 减少 i
            else:
                if i == 0: max_of_left = B[j-1]     # A从0开始划分
                elif j == 0: max_of_left = A[i-1]
                else: max_of_left = max(A[i-1], B[j-1])   # 左半部分的最大值

                if(m + n) % 2 == 1:     # 元素的总数为奇数，左半部分多的那个即为最大值
                    return max_of_left

                if i == m: min_of_right = B[j]
                elif j == n: min_of_right = A[i]
                else: min_of_right = min(A[i], B[j])     # 右半部分的最小值

                return (max_of_left + min_of_right) / 2.0



    # 归并方法
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        result = sorted(nums1 + nums2)
        lenth = len(result)
        if lenth % 2 == 0:
            return (result[lenth//2-1] + result[lenth//2]) / 2.0
        else:
            return result[lenth//2]




if __name__ == "__main__":
    nums1 = [1, 3]
    nums2 = [2]
    print(Solution().findMedianSortedArrays1(nums1, nums2))