class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // compute dist from each point in O(1), total O(N) times
        // determine whether in k smallest
        priority_queue<pair<int, int>> dist;
        for(int i = 0; i < points.size(); i++)
        {
            int cdist = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(dist.size() < k)
            {
                dist.push(make_pair(cdist, i));
            }
            else
            {
                if(cdist < dist.top().first)
                {
                    dist.pop();
                    dist.push(make_pair(cdist, i));
                }
            }
        }
        vector<vector<int>> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(points[dist.top().second]);
            dist.pop();
        }
        return res;
    }
};
