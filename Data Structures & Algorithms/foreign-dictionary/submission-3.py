class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        # this problem is ultimately just a dag
        # we return a valid topological sorting of this dag
        # if it isnt a dag then we return ""
        # all we care about are words right next to each other
        graph = [set() for _ in range(26)]
        appears = [False] * 26
        for w in words:
            for c in w:
                appears[ord(c) - ord('a')] = True
        for i in range(len(words) - 1):
            # create graph
            for j in range(len(words[i])):
                if j == len(words[i + 1]):
                    return ""
                if words[i][j] != words[i + 1][j]:
                    graph[ord(words[i + 1][j]) - ord("a")].add(ord(words[i][j]) - ord("a"))
                    break
        res = ""
        for i in range(26):
            for j in range(26):
                if appears[j] == True and len(graph[j]) == 0:
                    res += chr(ord("a") + j)
                    for k in range(26):
                        graph[k].discard(j)
                    appears[j] = False
        for i in range(26):
            if appears[i] == True:
                return ""
        return res
