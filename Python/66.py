class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        # 转化为字符串处理
        number = int(''.join(str(digit) for digit in digits)) + 1
        output = []
        for num in str(number):
            output.append(int(num))
        return output

    def plusOne1(self, digits):
        num = 1
        for i in range(len(digits)):
            num += digits[-i-1] * 10**i      # 倒序
        return [int(x) for x in str(num)]

    # 考虑进位的一般情况
    def plusOne2(self, digits):
        digits[:] = [0] + digits
        digits[-1] += 1
        # 倒序，以-1为步长
        for i in range(len(digits)-1, 0, -1):
            if digits[i] == 10:
                digits[i] = 0
                digits[i-1] += 1
            elif digits[i] < 10:
                break
        if digits[0] == 0:      # 前导0的情况
             digits[:] = digits[1:]
        return digits



if __name__ == "__main__":
    print(Solution().plusOne2([1, 2, 3]))


