class Solution:
    def findPeakGrid(self, mat: list[list[int]]) -> list[int]:
        m: int = len(mat)
        n: int = len(mat[0])

        lo: int = -1
        hi: int = m

        while hi - lo > 1:
            mid: int = lo + (hi - lo) // 2

            current_row: list[int] = mat[mid]

            # Find max element in current row
            max_pos: int = -1
            max_x: int = 0
            for i in range(n):
                x: int = current_row[i]
                if x > max_x:
                    max_x = x
                    max_pos = i

            up: int = mat[mid - 1][max_pos] if mid - 1 >= 0 else -1
            down: int = mat[mid + 1][max_pos] if mid + 1 < m else -1

            if max_x > up and max_x > down:
                return (mid, max_pos)

            elif up > max_x:
                hi = mid
            else:
                lo = mid
