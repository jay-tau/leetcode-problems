class Solution:
    def findMin(self, nums: list[int]) -> int:
        def condition(l: list[int], i: int) -> bool:
            return l[i] <= l[-1]

        n: int = len(nums)

        lo: int = -1
        hi: int = n

        while hi - lo > 1:
            mid: int = lo + (hi - lo) // 2
            if condition(nums, mid):
                hi = mid
            else:
                lo = mid

        return nums[hi]
