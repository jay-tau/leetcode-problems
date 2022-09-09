class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Solution is O(n)
        # Note that there is only 1 index pair which satisfies
        d = {} # {element:index}
        for i in range(len(nums)):
            a = nums[i]
            b = target - nums[i]
            if b in d:
                # Return statement occurs before appending to dictionary. Reason: Dry run nums=[3, 3] and target=6
                return [d[b], i] # return [index of b, i]
            # Add {current_element: index} to dictionary
            d[a] = i