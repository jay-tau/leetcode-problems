class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        i = 0
        
        for chars in zip(*strs):
            
            if len(set(chars)) == 1:
                i += 1
            else:
                break
        
        return strs[0][:i]
        