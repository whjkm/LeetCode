class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 利用集合去重
        return sum(set(nums))*2 - sum(nums)

    # 利用字典存储
    def singleNumber1(self, nums):
        dict = {}
        for num in nums:
            dict[num] = dict.get(num, 0) + 1
        for key, value in dict.items():
            if value == 1:
                return key

    # 利用异或操作
    def singleNumber2(self, nums):
        res = 0
        for num in nums:
            res ^= num
        return res

if __name__ == "__main__":
    print(Solution().singleNumber2([4,1,2,2,1]))