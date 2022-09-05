class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # print(sorted(nums1+nums2))
        combined = sorted(nums1+nums2)
        n = len(combined)
        if n % 2 != 0:
            median = combined[ceil(len(combined)/2) - 1]
        else:
            median = (combined[ceil(len(combined)/2) - 1] + combined[ceil(len(combined)/2)])/2.0
        return median