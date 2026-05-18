class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // just bfs with a priority queue
        // hardest part is impl.
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < times.size(); i++)
        {
            graph[times[i][0]-1].push_back(make_pair(times[i][1]-1, times[i][2]));
        }
        vector<int> vis(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bfs;
        bfs.push(make_pair(0, k-1));
        pair<int, int> curr;
        while(!bfs.empty())
        {
            curr = bfs.top();
            bfs.pop();
            if(vis[curr.second] != -1) continue;
            vis[curr.second] = curr.first;
            for(int i = 0; i < graph[curr.second].size(); i++)
            {
                if(vis[graph[curr.second][i].first] != -1) continue;
                bfs.push(make_pair(curr.first+graph[curr.second][i].second, graph[curr.second][i].first));
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == -1) return -1;
            res = max(res, vis[i]);
        }
        return res;
    }
};
