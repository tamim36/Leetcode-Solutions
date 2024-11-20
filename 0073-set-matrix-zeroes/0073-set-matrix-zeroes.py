class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        r = len(matrix)
        c = len(matrix[0])
        zero_row = [0] * r
        zero_col = [0] * c

        for i in range(r):
            for j in range(c):
                if (matrix[i][j] == 0):
                    zero_row[i] = 1
                    zero_col[j] = 1

        for i in range(r):
            for j in range(c):
                if (zero_row[i] == 1 or zero_col[j] == 1):
                    matrix[i][j] = 0
        