class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # O(n) time and O(n) space
        count = {}
        for num in nums:
            count[num] = 1
        ans = set()
        for i in range(1, len(nums)+1):
            if i not in count:
                ans.add(i)
        return ans