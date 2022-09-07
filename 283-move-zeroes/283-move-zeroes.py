class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # zero_count = nums.count(0)
        # nums = [x for x in nums_copy if x != 0] + ([0] * zero_count)
        # print(nums)
        current_pos = 0
        for i in range(len(nums)):
            if nums[current_pos] == 0:
                nums.pop(current_pos)
                nums.append(0)
            else:
                current_pos += 1
        print(nums)