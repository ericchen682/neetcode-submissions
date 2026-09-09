class Solution:
    def solve(self, s: str, curr: str, ind: int, clist: List[str], res: List[List[str]]) -> None:
        # attempt add curr
        # attempt add extra letter
        if ind == len(s):
            if len(curr) == 0:
                res.append(clist[:])
            return
        
        curr += s[ind]
        ind += 1
        if len(curr) > 0:
            # check if curr is palindrome
            isPalindrome = True
            for i in range(len(curr)//2):
                if curr[i] != curr[-i-1]:
                    isPalindrome = False
                    break
            if isPalindrome:
                clist.append(curr)
                self.solve(s, "", ind, clist, res)
                clist.pop()
        
        self.solve(s, curr, ind, clist, res)

    def partition(self, s: str) -> List[List[str]]:
        # each point in time we have a decision
        # attempt to add curr as palindrome
        # or append an additional letter
        res = []
        self.solve(s, "", 0, [], res)
        return res
