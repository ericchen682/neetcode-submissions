class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # n - 1 edges
        # there are no cycles
        # connected
        # we are given n - 1 edges
        # we must determine if graph is connected
        # simple bfs
        if len(edges) != (n - 1):
            return False
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        vis = [False] * n
        cnt = 1
        # start from 0
        vis[0] = True
        stack = [0]
        while len(stack) > 0:
            u = stack[-1]
            stack.pop()
            for v in graph[u]:
                if vis[v] is True:
                    continue
                stack.append(v)
                vis[v] = True
                cnt += 1
        if cnt == n:
            return True
        return False