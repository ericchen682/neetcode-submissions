import string

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # s of uppercase chars
        # k replacements
        # we want to find longest string
        # loop thru each char in alphabet
        res = 0
        n = len(s)
        for char in string.ascii_uppercase:
            l = 0
            r = 0
            miss = 0
            while r < n:
                if s[r] != char:
                    miss = miss + 1
                    while miss > k:
                        if s[l] != char:
                            miss = miss - 1
                        l = l + 1
                res = max(res, r - l + 1)
                r = r + 1
        return res
