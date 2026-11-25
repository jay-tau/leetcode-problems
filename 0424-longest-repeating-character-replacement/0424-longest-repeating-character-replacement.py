import string

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n: int = len(s)

        left: int = 0

        freq: dict[str, int] = dict.fromkeys(string.ascii_uppercase, 0)
        max_len: int = 0

        for right in range(n):
            current_char = s[right]
            # Expand
            freq[current_char] += 1

            # Shrink if needed
            while (right - left + 1) - (max(freq.values())) > k and left <= right:
                left_char = s[left]
                
                freq[left_char] -= 1
                left += 1

            # Update answer
            max_len = max(max_len, right - left + 1)
        
        return max_len