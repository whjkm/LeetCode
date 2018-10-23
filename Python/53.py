class Solution:

    # Kadane's algorithm
    def maxSubArray(self, nums):

        if not nums:
            return 0

        curSum = maxSum = nums[0]

        for num in nums[1:]:
            curSum = max(num, curSum + num)
            maxSum = max(curSum, maxSum)

        return maxSum


if __name__ == "__main__":
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(Solution().maxSubArray(nums))