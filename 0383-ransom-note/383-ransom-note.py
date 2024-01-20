class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        alphabets = 'abcdefghijklmnopqrstuvwxyz'
        # print(len(alphabets))
        ransomCount = {}; magazineCount = {}
        for alphabet in alphabets:
            ransomCount[alphabet] = 0
            magazineCount[alphabet] = 0
        # print(ransomCount)
        for ransomLetter in ransomNote:
            ransomCount[ransomLetter] += 1
        for magazineLetter in magazine:
            magazineCount[magazineLetter] += 1
        # print(magazineCount)
        for alphabet in alphabets:
            if magazineCount[alphabet] >= ransomCount[alphabet]:
                continue
            else:
                return False
        return True