class Solution:
    def splitArray(self, nums: list[int], k: int) -> int:
        lo: int = max(nums) - 1
        hi: int = sum(nums) + 1

        while hi - lo > 1:
            mid: int = lo + (hi - lo) // 2
            possible_max_sum: int = mid

            splits: int = 1
            current_sum = 0
            for x in nums:
                current_sum += x
                if current_sum > possible_max_sum:
                    splits += 1
                    current_sum = x

            if splits <= k:
                # If we have less splits, we can divide valid arrays into smaller ones
                hi = mid
            else:
                lo = mid

        return hi
