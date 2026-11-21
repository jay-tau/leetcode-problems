from math import ceil


class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        def _condition(l: list[int], possible_speed: int, target_time: int) -> bool:
            total_time: int = sum([ceil(x / possible_speed) for x in l])

            return total_time <= target_time

        lo: int = 0
        hi: int = max(piles) + 1

        while hi - lo > 1:
            mid = lo + (hi - lo) // 2

            if _condition(piles, mid, h):
                hi = mid
            else:
                lo = mid

        return hi
