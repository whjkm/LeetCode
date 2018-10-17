class Solution(object):
    # threeSum transfer twoSum : a + b = -c
    # 有点类似于快排的思想
    def threeSum(self, nums):
        nums.sort()           # 先将列表元素进行排序
        N, results = len(nums), []
        for i in range(N):
            if i > 0 and nums[i] == nums[i-1]:     # 去除相同的结果
                continue
            target = nums[i] * -1
            s, e = i+1, N-1
            while s < e:
                if nums[s] + nums[e] == target:
                    results.append([nums[i], nums[s], nums[e]])
                    s = s + 1
                    while s < e and nums[s] == nums[s-1]:       # 去除相同的结果
                        s = s + 1
                elif nums[s] + nums[e] < target:
                    s = s + 1
                else:
                    e = e - 1
        return results



if __name__ == "__main__":
    nums = [-1, 0, 1, 2, -1, -4]
    print(Solution().threeSum(nums))


