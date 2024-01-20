from math import comb

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        # We know that each row is the binomial coefficients (nCr)
        pascalTriangle = []
        for n in range(numRows):
            pascalTriangle.append([comb(n, r) for r in range(n+1)])
        return pascalTriangle
                