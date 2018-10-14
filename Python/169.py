class Solution:

    # 题意中给出的相同元素的数量会大于数组长度的一半
    # 直接对元素进行排序，输出中间的那个元素
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return nums[len(nums)//2]

    # 选择一个候选主元素，与当前元素相同就加一，不是当前元素就减一
    def majorityElement1(self, nums):
        count = 0
        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)
        return candidate






if __name__ == "__main__":
    nums = [3, 2, 3]
    print(Solution().majorityElement1(nums))