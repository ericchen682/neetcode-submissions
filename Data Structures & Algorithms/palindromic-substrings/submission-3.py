class Solution:
    def countSubstrings(self, s: str) -> int:
        # return # of substrings within s that are palindromes
        res = 1
        for i in range(len(s) - 1):
            j = 0
            while i >= j and (i + j) < len(s) and s[i - j] == s[i + j]:
                res += 1
                j += 1
            j = 0
            while i >= j and (i + j + 1) < len(s) and s[i - j] == s[i + j + 1]:
                res += 1
                j += 1
        return res