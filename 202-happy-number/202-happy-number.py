class Solution:
    def isHappy(self, n: int) -> bool:
        d = set()
        while n != 1:
            n = sum(map(lambda x: x**2, map(int, list(str(n)))))
            if n in d:
                break
            else:
                d.add(n)
        return (n == 1)