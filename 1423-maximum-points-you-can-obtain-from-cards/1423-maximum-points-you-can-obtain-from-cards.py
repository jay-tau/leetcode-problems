from functools import cache


class Solution:
    def maxScore(self, cardPoints: list[int], k: int) -> int:
        n: int = len(cardPoints)

        # @cache
        # def S(x):
        #     if x == 0:
        #         return sum(cardPoints[n - k :])
        #     return S(x - 1) + cardPoints[x - 1] - cardPoints[n - k + x - 1]

        # return max(S(x) for x in range(k + 1))

        current_sum: int = sum(cardPoints[(n - k) :])
        max_sum: int = current_sum

        for i in range(1, k + 1):
            current_sum = current_sum + cardPoints[i - 1] - cardPoints[n - k + i - 1]
            max_sum = max(max_sum, current_sum)

        return max_sum
