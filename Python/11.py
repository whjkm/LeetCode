class Solution:

    # 类似于两分查找的思想，从两端进行查找，逐渐更新最大值
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r = 0, len(height) - 1
        max_area = 0
        while l < r:
            temp = min(height[l], height[r]) * (r - l)
            max_area = max(max_area, temp)
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1

        return max_area


if __name__ == "__main__":
    nums = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    print(Solution().maxArea(nums))
