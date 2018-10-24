class Solution:
    # 题意是求出列表的所有排列
    # 类似于DP的思想，每次在前一个状态上插入新的元素
    # 以[1,2,3]为例，初始插入[1]到结果列表，然后插入[2],这时就有两种插法，可以插入到[1]前，或者[1]后
    # 将两种结果保存到结果列表，[1,2],[2,1]
    # 然后插入[3],在上面的基础上继续插值，可以插入的位置就有3个，可以在列表的最开始，中间，或者最后
    # [3,1,2],[1,3,2],[1,2,3]
    # [3,2,1],[2,3,1],[2,1,3]，然后将结果保存到结果数组
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        perms = [[]]
        for num in nums:
            new_perms = []
            for perm in perms:
                for i in range(len(perm) + 1):
                    new_perms.append(perm[:i] + [num] + perm[i:])    # insert num
            perms = new_perms
        return perms

    # Using the library
    def permute1(self, nums):
        return list(itertools.permutations(nums))



if __name__ == "__main__":
    nums = [1, 2, 3]
    print(Solution().permute(nums))