class Solution:
    def singleNonDuplicate(self, nums: list[int]) -> int:
        n: int = len(nums)
        lo: int = 0
        hi: int = n - 1

        while hi >= lo:
            mid: int = lo + (hi - lo) // 2

            if mid+1 < n and nums[mid] == nums[mid+1]:
                left_len = mid - lo
                right_len = hi - (mid + 1)

                if left_len % 2 == 0:
                    lo = (mid + 1) + 1
                else:
                    hi = mid - 1
            elif mid -1 >= 0 and nums[mid] == nums[mid - 1]:
                left_len = (mid - 1) - lo
                right_len = hi - mid

                if left_len % 2 == 0:
                    lo = mid + 1
                else:
                    hi = (mid - 1) - 1
            else: # Neither neighbor is equal
                return nums[mid]