class Solution:
    def isHappy(self, n):
        mem = set()
        while n != 1:
            n = sum([int(i) ** 2 for i in str(n)])    # 求和
            if n in mem:
                return False   # 迭代出现不等于1的环
            else:
                mem.add(n)
        else:
            return True


    # Floyd Cycle detection algorithm
    def isHappy1(self,n):
        r1 = self.step(n)
        r2 = self.step(r1)
        while(r1 != 1):
            if(r1 == r2):
                return False
            else:
                r1 = self.step(r1)
                r2 = self.step(self.step(r2))
        return True

    # 求平方和
    def step(self,n):
        result = 0
        while(n):
            result += pow(n%10, 2)
            n = n // 10
        return result



if __name__ == "__main__":
    print(Solution().isHappy1(19))