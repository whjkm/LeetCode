class Solution:

    # TopDown 自顶向下
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0 for i in range(n + 1)]
        dp[0] = dp[1] = 1
        for i in range(2, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]

    # Bottom Up
    def climbStairs1(self, n):
        lookup = [None] * (n+1)

        # Memoization -> Bottom Up
        def fib(n):
            if n==0 or n==1:
                lookup[n] = 1
            if lookup[n] is None:
                lookup[n] = fib(n-1) + fib(n-2)
            return lookup[n]
        res = fib(n)
        return res

if __name__ == "__main__":
    print(Solution().climbStairs1(4))