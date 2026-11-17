class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        n: int = len(nums)

        prefix_sums: list[int] = [0] * (n+1)
        d = defaultdict(int, { 0:1 })

        ans: int = 0

        for i in range(n):
            prefix_sums[i+1] = prefix_sums[i] + nums[i]
            current_prefix_sum = prefix_sums[i+1]

            target = current_prefix_sum - k # k = current_prefix_sum - target
            if target in d:
                ans += d[target]
            
            d[current_prefix_sum] += 1 # Insert current prefix-sum


        return ans