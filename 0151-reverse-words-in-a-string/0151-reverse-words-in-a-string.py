class Solution:
    def reverseWords(self, s: str) -> str:
        l = s.strip().split()
        return (' '.join(l[::-1]))