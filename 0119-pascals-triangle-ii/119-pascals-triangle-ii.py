from math import comb

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        return [comb(rowIndex, r) for r in range(rowIndex+1)]