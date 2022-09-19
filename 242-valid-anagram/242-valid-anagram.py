class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        d_s = {}
        for char_s in s:
            if char_s in d_s:
                d_s[char_s] += 1
            else:
                d_s[char_s] = 1
        # print(d_s)
        d_t = {}
        for char_t in t:
            if char_t in d_t:
                d_t[char_t] += 1
            else:
                d_t[char_t] = 1
        # print(d_t)
        if len(d_s) != len(d_t):
            # print('len')
            return False
        else:
            for char in d_s:
                try:
                    count_s = d_s[char]
                    count_t = d_t[char]
                    if count_s != count_t:
                        return False
                except KeyError:
                    # Key not found in both dictionaries
                    return False
        return True