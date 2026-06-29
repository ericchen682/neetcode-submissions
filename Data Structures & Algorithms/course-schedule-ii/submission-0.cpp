class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // essentially a dag
        vector<vector<int>> graph(numCourses);
        // attempt a topological sort
        vector<int> res;
        vector<int> enteringEdges(numCourses);
        vector<bool> vis(numCourses, false);
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            // edge from v -> u
            enteringEdges[u]++;
            graph[v].push_back(u);
        }
        for(int i = 0; i < numCourses; i++)
        {
            for(int j = 0; j < numCourses; j++)
            {
                if(vis[j]) continue;
                if(enteringEdges[j] != 0) continue;
                res.push_back(j);
                for(auto u : graph[j])
                    enteringEdges[u]--;
                vis[j] = true;
                break;
            }
        }
        if(res.size() != numCourses)
            return {};
        return res;
    }
};
