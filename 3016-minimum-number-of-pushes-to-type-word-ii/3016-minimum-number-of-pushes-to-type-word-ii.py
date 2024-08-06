class Solution:
    def minimumPushes(self, word: str) -> int:
        return sum(((1 + (i // 8)) * f for i, f in enumerate(sorted(Counter(word).values(), reverse=True))))