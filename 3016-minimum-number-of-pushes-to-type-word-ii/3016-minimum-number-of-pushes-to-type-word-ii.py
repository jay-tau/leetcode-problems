class Solution:
    def minimumPushes(self, word: str) -> int:
        f = Counter(word)
    
        ans = 0
        
        l = sorted(f.values(), reverse=True)
        # print(l)
        
        for i, f in enumerate(l):
            # print(i, f)
            ans += (1 + (i // 8)) * f
        
        return ans