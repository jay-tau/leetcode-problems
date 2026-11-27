from collections import deque


class Solution:
    def floodFill(
        self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        m: int = len(image)
        n: int = len(image[0])

        original_color: int = image[sr][sc]

        if color == original_color:
            return image

        q: deque[tuple[int, int]] = deque( [ (sr, sc) ] )

        while q:
            row, col = q.popleft()

            if not (0 <= row < m and 0 <= col < n):
                continue
            if image[row][col] != original_color:
                continue

            image[row][col] = color

            dx = (-1, 1, 0, 0)
            dy = (0, 0, -1, 1)
            q.extend(
                (row + dx[i], col + dy[i]) for i in range(4)
            )

        return image
