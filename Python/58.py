class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """

        str = s.split()                   # 去除字符串中的空格
        s1 = "".join(str[-1:])            # 将单词列表中的最后一个单词取出
        return len(s1)

    '''
    def lengthOfLastWord(self, s):
        return 0 if not s.rsplit() else len(s.split()[-1])
    '''

if __name__ == "__main__":
    s = " "
    Solution().lengthOfLastWord(s)
