class Solution:
    # 筛选法
    def countPrimes(self, n):
        if n < 3:
            return 0
        primes = [True] * n
        primes[0] = primes[1] = False
        for i in range(2, int(n ** 0.5) + 1):
            if primes[i]:
                primes[i*i: n: i] = [False] * len(primes[i * i: n: i])
        return sum(primes)

if __name__ == "__main__":
    print(Solution().countPrimes(10))
