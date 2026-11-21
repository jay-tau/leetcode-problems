class Solution:
    def search(self, nums: list[int], target: int) -> bool:
        # Inclusive binary search when possible
        n: int = len(nums)
        lo: int = 0
        hi: int = n - 1

        while lo <= hi:
            mid: int = lo + (hi - lo) // 2

            if nums[mid] == target:
                return True

            if nums[mid] == nums[lo]:  # if duplicates
                lo += 1  # perform 1 linear search step
                continue
            elif nums[lo] < nums[mid]:  # Left half is sorted (binary search)
                if nums[lo] <= target < nums[mid]:
                    hi = mid - 1
                else:
                    lo = mid + 1
            else:  # Right half is sorted (binary search)
                if nums[mid] < target <= nums[hi]:
                    lo = mid + 1
                else:
                    hi = mid - 1

        return False
