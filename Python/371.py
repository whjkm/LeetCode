import statistics
class Solution:
    ''''
    def getSum(self, a, b):
        x = statistics.mean([a, b])
        print(x)
        print(x * 2)
        return round(x * 2)
    '''

    def getSum(self, a, b):
        x = statistics.harmonic_mean([a, b])
        return round((x**(-1)) * 2 * a * b)
    # 位运算
    def getSum1(self, a, b):
        if a == -b:
            return 0
        if abs(a) > abs(b):
            a, b = b, a
        if a < 0:
            return -self.getSum(-a, -b)
        while b:
            c = a & b
            a ^= b
            b = c << 1
        return a

if __name__ == "__main__":
    print(Solution().getSum1(1, 2))