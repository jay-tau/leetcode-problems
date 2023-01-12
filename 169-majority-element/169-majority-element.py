class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = {}
        for num in nums:
            if num in d:
                d[num] += 1
            else:
                d[num] = 1
        max_count = 0; max_element = -1
        for num in d:
            if d[num] > max_count:
                max_count = d[num]
                max_element = num
        return max_element