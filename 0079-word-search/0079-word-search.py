class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        m: int = len(board)
        n: int = len(board[0])

        def is_eligible(cell: tuple[int, int], word_idx: int) -> bool:
            x: int
            y: int
            x, y = cell

            return (0 <= x < m and 0 <= y < n) and not visited[x][y] and board[x][y] == word[word_idx]
        

        def dfs(x: int, y: int, word_idx: int, visited: list[list[bool]]) -> bool:
            if word_idx == len(word):
                return True
            
            visited[x][y] = True

            dx = (-1, 1, 0, 0)
            dy = (0, 0, -1, 1)
            neighbors = ((x + dx[i], y + dy[i]) for i in range(4))

            for neighbor in neighbors:
                if is_eligible(neighbor, word_idx):
                    res: bool = dfs(neighbor[0], neighbor[1], word_idx+1, visited)
                    if res:
                        return True
            
            # Make this node free for future explorations
            visited[x][y] = False
            return False
        


        visited = [[False] * n for i in range(m)]

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    res: bool = dfs(i, j, 1, visited)
                    if res:
                        return True
        
        return False
                    
