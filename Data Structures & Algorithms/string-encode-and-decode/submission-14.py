class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res = res + str(len(s)) + "#" + s
        return res

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            clen = 0
            while s[i] != "#":
                clen *= 10
                clen += int(s[i])
                i += 1
            # now we have s[i] is "#"
            i += 1
            res.append(s[i:(i + clen)])
            i += clen
        return res
                