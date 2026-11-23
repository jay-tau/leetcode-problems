from functools import cache


class Solution:
    def maxScore(self, cardPoints: list[int], k: int) -> int:
        n: int = len(cardPoints)

        @cache
        def S(x):
            if x == 0:
                return sum(cardPoints[n - k :])
            return S(x - 1) + cardPoints[x - 1] - cardPoints[n - k + x - 1]

        return max(S(x) for x in range(k + 1))
