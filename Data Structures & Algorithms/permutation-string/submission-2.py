class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # maintain rolling window
        arr1 = [0] * 26
        arr2 = [0] * 26
        for c in s1:
            arr1[ord(c) - ord('a')] += 1
        clen = 0
        for i in range(len(s2)):
            clen += 1
            if clen > len(s1):
                arr2[ord(s2[i - clen + 1]) - ord('a')] -= 1
                clen -= 1
            arr2[ord(s2[i]) - ord('a')] += 1
            if arr1 == arr2:
                return True
        return False