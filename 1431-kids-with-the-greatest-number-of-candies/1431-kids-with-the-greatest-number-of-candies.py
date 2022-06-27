class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_original = max(candies)
        ans = []
        for i in range(len(candies)):
            if (candies[i]+extraCandies) >= max_original:
                ans.append(True)
            else:
                ans.append(False)
        return ans