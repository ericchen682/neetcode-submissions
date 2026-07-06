class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            // auto [ u, v ] = edges[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        stack<int> bfs;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i])
                continue;
            res++;
            bfs.push(i);
            vis[i] = true;
            while(!bfs.empty())
            {
                int u = bfs.top();
                bfs.pop();
                for(auto v : graph[u])
                {
                    if(vis[v])
                        continue;
                    bfs.push(v);
                    vis[v] = true;
                } 
            }
        }
        return res;
    }
};
