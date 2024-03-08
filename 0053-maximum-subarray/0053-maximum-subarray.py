class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = nums[0]
        current_sum = 0

        for num in nums:
            if current_sum < 0:  # Do not carry -ve sums forward
                current_sum = 0  # Reset the front end of the sliding window

            current_sum += num
            max_sum = max(max_sum, current_sum)

        return max_sum
