class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        n: int = len(nums)

        subsets: list[list[int]] = []

        for i in range(2**n):
            bitstring = bin(i)[2:]  # Remove "0b"
            bitstring = "0" * (n - len(bitstring)) + bitstring

            subset: list[int] = []
            for j in range(n):
                if bitstring[j] == "1":
                    subset.append(nums[j])

            subsets.append(subset)

        return subsets
