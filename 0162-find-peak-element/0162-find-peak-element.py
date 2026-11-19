class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        def _condition(l: list[int], i: int) -> bool:
            if i == 0:
                return False

            return l[i - 1] > l[i]

        n: int = len(nums)

        lo: int = -1
        hi: int = n

        while hi - lo > 1:
            mid: int = lo + (hi - lo) // 2
            if _condition(nums, mid):
                hi = mid
            else:  # Not descending. Move right
                lo = mid

        return lo  # Since it is minimum, ans is found in lo
