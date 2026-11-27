from collections import deque


class Solution:
    def floodFill(
        self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        m: int = len(image)
        n: int = len(image[0])

        original_color: int = image[sr][sc]

        if color == original_color:
            return image


        def is_valid(x: int, y: int) -> bool:
            return 0 <= x < m and 0 <= y < n
        def is_visited(x: int, y: int) -> bool:
            return image[x][y] != original_color


        q: deque[tuple[int, int]] = deque( [ (sr, sc) ] )
        image[sr][sc] = color

        while q:
            row, col = q.popleft()

            # image[row][col] = color

            dx = (-1, 1, 0, 0)
            dy = (0, 0, -1, 1)
            for i in range(4):
                neighbor_x, neighbor_y = row + dx[i], col + dy[i]
                if is_valid(neighbor_x, neighbor_y) and not is_visited(neighbor_x, neighbor_y):
                    q.append(
                        (neighbor_x, neighbor_y)
                    )
                    image[neighbor_x][neighbor_y] = color

        return image
