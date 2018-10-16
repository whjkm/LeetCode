class Solution:
    # 倒序处理
    def romanToInt1(self, s):
        roman_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        val = 0
        prev_roman = 0
        rev_s = s[::-1]     # 倒序
        for i in range(len(s)):
            roman_to_int = roman_dict[rev_s[i]]
            if roman_to_int < prev_roman:
                val = val - roman_to_int
            else:
                val = val + roman_to_int
            prev_roman = roman_to_int
        return val

    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        num = 0
        dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000, 'IV': -2, 'IX': -2, 'XL': -20, 'XC': -20, 'CD': -200, 'CM': -200}
        for key in dict:
            num = num + s.count(key) * dict[key]
        return num

if __name__ == "__main__":
    s = "MCMXCIV"
    print(Solution().romanToInt1(s))