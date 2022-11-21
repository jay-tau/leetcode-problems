class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        target = []
        for i in range(len(nums)//2):
            freq, val = nums[2*i], nums[(2*i) + 1]
            target.extend([val for _ in range(freq)])
        return target