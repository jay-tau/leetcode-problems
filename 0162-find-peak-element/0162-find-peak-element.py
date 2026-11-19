class Solution:

    def findPeakElement(self, nums: list[int]) -> int:
        def _condition(l: list[int], i: int) -> bool:
            n: int = len(l)
            if i == 0:
                return False
            if l[i-1] > l[i]:
                return True
            return False

        n: int = len(nums)
        
        lo: int = -1
        hi: int = n

        while hi - lo > 1:
            mid: int = lo + (hi-lo)//2
            print(f"lo: {lo} mid: {mid} hi: {hi}")
            if _condition(nums, mid):
                hi = mid
            else:
                # not desc. move right
                lo = mid
        
        return lo # Since it is minimum, ans is found in lo