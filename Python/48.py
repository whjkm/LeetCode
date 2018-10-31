class Solution:
    def rotate(self, matrix):
        #matrix[::] = zip(*matrix[::-1])
        matrix[:] = map(list, zip(*matrix[::-1]))     # 先按照元组的顺序排列，然后解压成二维列表的形式
        print(matrix)

    def rotate1(self, matrix):
        # 先对列表进行装置操作，然后对列进行两两交换
        n = len(matrix)
        # 转置
        for i in range(n):
            for j in range(n):
                if j < i:
                    matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        for l in matrix:
            l.reverse()     # 对每一行进行反转





if __name__ == "__main__":
    matrix = [
               [1, 2, 3],
               [4, 5, 6],
               [7, 8, 9]
             ]
    Solution().rotate1(matrix)
