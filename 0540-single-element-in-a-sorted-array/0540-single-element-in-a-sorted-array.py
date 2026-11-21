class Solution:
    def singleNonDuplicate(self, nums: list[int]) -> int:
        def _condition(l: list[int], i: int) -> bool:
            # Form pairs and check where they're not equal
            n: int = len(nums)

            if i == n - 1:
                return True

            if i % 2 == 0:
                return not l[i] == l[i + 1]
            else:
                return not l[i] == l[i - 1]

        n: int = len(nums)
        lo: int = -1
        hi: int = n

        while hi - lo > 1:
            mid = lo + (hi - lo) // 2

            if _condition(nums, mid):
                hi = mid
            else:
                lo = mid

        return nums[hi]
