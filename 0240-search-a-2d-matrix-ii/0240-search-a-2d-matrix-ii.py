class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        m: int = len(matrix)
        n: int = len(matrix[0])

        row: int = 0
        col: int = n - 1

        while (0 <= row < m and 0 <= col < n):
            x: int = matrix[row][col]

            if x == target:
                return True
            elif x < target:
                row += 1
            else:
                col -= 1
        
        return False