class Solution:
    def addDigits(self, num):

        #return self.addDigits(sum(int(i) for i in str(num))) if num >=10 else num

        '''
        while num > 9:
            num = sum(int(i) for i in str(num))
        return num
        '''

        # e.g 0 --> 0; 18 % 9 = 0, 18 --> 9; 19 % 9 = 1, 19 --> 1
        return (num if num == 0 else (9 if num % 9 == 0 else num % 9))

if __name__ == "__main__":
    print(Solution().addDigits(38))