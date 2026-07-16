class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        // just make a dag
        vector<vector<int>> graph(n);
        vector<int> edgesIn(n, 0);
        vector<bool> vis(n, false);
        for(int i = 0; i < edges.size(); i++)
        {
            // edge from b -> a
            graph[edges[i][1]].push_back(edges[i][0]);
            edgesIn[edges[i][0]]++;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(edgesIn[j] != 0 || vis[j])
                    continue;
                vis[j] = true;
                for(auto node : graph[j])
                    edgesIn[node]--;
            }
        }
        for(int i = 0; i < n; i++)
            if(edgesIn[i])
                return false;
        return true;
    }
};
