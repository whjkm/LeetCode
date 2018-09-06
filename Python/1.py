class Solution(object):
    def twoSum(self, num, target):
        for i in num:
            j = target - i
            tmp_nums_start_index = num.index(i) + 1      # 第一个值的下标位置
            tmp_nums = num[tmp_nums_start_index:]        # 列表中去除第一个元素
            if j in tmp_nums:      # 在余下的值中找第二个元素的下标
                return [num.index(i), tmp_nums_start_index + tmp_nums.index(j)]

    def twoSum1(self, num, target):
        lookup = {}       # 用字典存储
        for i, n in enumerate(num):       # 遍历列表中的元素和下标
            if target - n in lookup:
                return [lookup[target - n], i]
            lookup[n] = i

    def twoSum2(self, nums, target):
        for i in range(0, len(nums)-1):
            second_val = target - nums[i]
            if second_val in nums[i+1:]:
                return [i, nums.index(second_val, i+1)]


if __name__ == '__main__':
    print(Solution().twoSum2((2, 7, 11, 15), 9))







