class Solution:
    
    def spiralOrder1(self, matrix):
        if matrix == []:
            return matrix
        m, n = len(matrix), len(matrix[0])
        top, bottom = 0, m-1
        left, right = 0, n-1
        res = []
        while top < bottom and left < right:
            res.extend(matrix[top][left:right])
            res.extend([matrix[i][right] for i in range(top, bottom)])
            res.extend(matrix[bottom][right:left:-1])
            res.extend([matrix[i][left] for i in range(bottom, top, -1)])
            top += 1; bottom -= 1
            left += 1; right -= 1
        if top == bottom:
            res.extend(matrix[top][left:right+1])
        elif left == right:
            res.extend([matrix[i][right] for i in range(top, bottom+1)])
        return res

    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        return matrix and [*matrix.pop(0)] + self.spiralOrder([*zip(*matrix)][::-1])

    # 转化过程 orz，每次提取第一行， 然后再将当前矩阵按逆时针旋转90度
    '''
    spiralOrder([[1, 2, 3],
                [4, 5, 6],
                [7, 8, 9]])
    = [1, 2, 3] + spiralOrder([[6, 9],
                               [5, 8],
                               [4, 7]])
    = [1, 2, 3] + [6, 9] + spiralOrder([[8,7],
                                        [5,4])
    = [1, 2, 3] + [6, 9] + [8, 7] + spiralOrder([[4],
                                                [5]])
    = [1, 2, 3] + [6, 9] + [8, 7] + [4] + spiralOrder([[5]])
    
    = [1, 2, 3] + [6, 9] + [8, 7] + [4] + [5] + spiralOrder([])
    
    = [1, 2, 3] + [6, 9] + [8, 7] + [4] + [5] + []
    
    = [1, 2, 3, 6, 9, 8, 7, 4, 5]
                                                
    '''


if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]
    print(Solution().spiralOrder1(matrix))