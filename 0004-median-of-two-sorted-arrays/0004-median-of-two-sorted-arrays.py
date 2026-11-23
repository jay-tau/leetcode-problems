from bisect import bisect_right


class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        def _condition(l1: int, l2: int, r1: int, r2: int) -> bool:
            return l1 <= r2
        m: int = len(nums1)
        n: int = len(nums2)
        N: int = m + n

        if n < m:
            return self.findMedianSortedArrays(nums2, nums1)

        lo: int = 0 - 1
        hi: int = m + 1

        while hi - lo > 1:
            mid: int = lo + (hi - lo) // 2

            cut1: int = mid
            cut2: int = N // 2 - mid

            l1 = (
                nums1[cut1 - 1] if 0 <= cut1 - 1 < m else float("-inf")
            )  # Take cut1 elements
            l2 = (
                nums2[cut2 - 1] if 0 <= cut2 - 1 < n else float("-inf")
            )  # Take cut2 elements

            r1 = nums1[cut1] if 0 <= cut1 < m else float("inf")
            r2 = nums2[cut2] if 0 <= cut2 < n else float("inf")

            if _condition(l1, l2, r1, r2):
                lo = mid
            else:
                hi = mid
        cut1 = lo
        cut2 = N // 2 - lo

        l1 = nums1[cut1 - 1] if 0 <= cut1 - 1 < m else float("-inf")
        l2 = nums2[cut2 - 1] if 0 <= cut2 - 1 < n else float("-inf")
        r1 = nums1[cut1] if 0 <= cut1 < m else float("inf")
        r2 = nums2[cut2] if 0 <= cut2 < n else float("inf")

        if N % 2 == 0:
            median = (max(l1, l2) + min(r1, r2)) / 2
        else:
            median = min(r1, r2)
        
        return median
