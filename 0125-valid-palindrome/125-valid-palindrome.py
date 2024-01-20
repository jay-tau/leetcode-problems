class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Read all characters. If isAlphaNumeric, then toLower. O(n)
        s_cleaned = ""
        for char in s:
            if char.isalnum():
                s_cleaned += char.lower()
        print(s_cleaned)
        # Reversing is also a O(n) operation
        if s_cleaned == s_cleaned[::-1]:
            return True
        else:
            return False