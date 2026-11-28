class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        m: int = len(board)
        n: int = len(board[0])
        

        def dfs(x: int, y: int, word_idx: int, visited: list[list[bool]]) -> bool:
            if word_idx == len(word):
                return True
            
            if not (0 <= x < m and 0 <= y < n):
                return False
            if visited[x][y]:
                return False
            if board[x][y] != word[word_idx]:
                return False
            
            visited[x][y] = True

            directions = ((-1, 0), (1, 0), (0, -1), (0, 1))

            for dx, dy in directions:
                nx, ny = x+dx, y+dy
                res: bool = dfs(nx, ny, word_idx+1, visited)
                if res:
                    visited[x][y] = False
                    return True
            
            # Make this node free for future explorations
            visited[x][y] = False
            return False
        


        visited = [[False] * n for i in range(m)]

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    res: bool = dfs(i, j, 0, visited)
                    if res:
                        return True
        
        return False
                    
