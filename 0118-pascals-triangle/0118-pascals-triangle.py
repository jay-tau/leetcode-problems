class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal_triangle = [[1]]
        
        for n in range(1, numRows):
            row = [comb(n, r) for r in range(n+1)]
            pascal_triangle.append(row)
    
        return pascal_triangle