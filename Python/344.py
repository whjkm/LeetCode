class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s[::-1]

    def reverseString1(self, s):
        r = list(s)
        i, j = 0, len(r) - 1
        while i < j:
            r[i], r[j] = r[j], r[i]
            i += 1
            j -= 1
        return "".join(r)

    def reverseString2(self, s):
        l = len(s)
        if l < 2:
            return s
        return self.reverseString2(s[l//2:]) + self.reverseString2(s[:l//2])



if __name__ == "__main__":
    print(Solution().reverseString2("hello"))
