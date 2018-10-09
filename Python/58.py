class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        str = s.split()
        s1 = "".join(str[-1:])
        return len(s1)

    '''
    def lengthOfLastWord(self, s):
        return 0 if not s.rsplit() else len(s.split()[-1])
    '''

if __name__ == "__main__":
    s = " "
    Solution().lengthOfLastWord(s)
