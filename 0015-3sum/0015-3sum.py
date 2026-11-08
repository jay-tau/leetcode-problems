class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        n: int = len(nums)
        nums.sort()

        ans: list[list[int]] = []

        for i in range(n):
            x = nums[i]

            if i >= 1 and nums[i] == nums[i - 1]:
                continue

            left: int = i + 1
            right: int = n - 1

            while left < right:
                current_sum = x + nums[left] + nums[right]

                if current_sum > 0:
                    right -= 1
                elif current_sum < 0:
                    left += 1
                else:  # Valid triplet
                    x_left = nums[left]
                    x_right = nums[right]
                    ans.append([x, x_left, x_right])

                    while left < n and nums[left] == x_left:
                        left += 1
                    while right > i and nums[right] == x_right:
                        right -= 1

        return ans
