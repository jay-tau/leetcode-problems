from collections import deque
from pprint import pprint


class Solution:
    def floodFill(
        self, image: list[list[int]], sr: int, sc: int, color: int
    ) -> list[list[int]]:
        m: int = len(image)
        n: int = len(image[0])

        original_color: int = image[sr][sc]

        if color == original_color:
            return image

        q: deque[tuple[int, int]] = deque([(sr, sc)])

        while q:
            row, col = q.popleft()

            if not (0 <= row < m and 0 <= col < n):
                continue
            if image[row][col] != original_color:
                continue

            image[row][col] = color

            q.extend(
                (
                    (row - 1, col),
                    (row + 1, col),
                    (row, col - 1),
                    (row, col + 1),
                )
            )

        return image
