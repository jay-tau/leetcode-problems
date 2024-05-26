class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        return [[comb(n, r) for r in range(n+1)] for n in range(0, numRows)]