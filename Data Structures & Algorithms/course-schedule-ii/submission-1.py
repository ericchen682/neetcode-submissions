class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # dag check topological sort
        graph = [[] for _ in range(numCourses)]
        inEdges = [0] * numCourses
        for u, v in prerequisites:
            graph[v].append(u)
            inEdges[u] += 1
        arr = []
        for i in range(numCourses):
            if inEdges[i] == 0:
                arr.append(i)
        res = []
        while len(arr) > 0:
            u = arr[-1]
            arr.pop()
            res.append(u)
            for v in graph[u]:
                inEdges[v] -= 1
                if inEdges[v] == 0:
                    arr.append(v)
        
        if len(res) == numCourses:
            return res
        return []
