class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        s = ([str(x) for x in range(1, n+1)])
        from itertools import permutations
        l = list(permutations(s))
        return ''.join(l[k-1])