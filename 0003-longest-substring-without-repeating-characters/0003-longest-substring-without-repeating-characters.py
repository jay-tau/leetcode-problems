class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n: int = len(s)

        left: int = 0
        right: int = 0

        chars_in_substring: set[str] = set()

        max_len: int = 0

        while right < n:
            current_char = s[right]

            if current_char not in chars_in_substring:
                chars_in_substring.add(current_char)
                right += 1
                current_len: int = right - left
                max_len = max(max_len, current_len)
            else:
                while True:
                    left_char = s[left]
                    chars_in_substring.remove(left_char)
                    left += 1

                    if current_char == left_char:
                        break

        return max_len
