class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        deque<pair<int, int>> ms;
        int n = temperatures.size();
        vector<int> res(n);
        ms.push_back(make_pair(temperatures[0], 0));
        for(int i = 1; i < n; i++)
        {
            while(!ms.empty() && temperatures[i] > ms.back().first)
            {
                res[ms.back().second] = i-ms.back().second;
                ms.pop_back();
            }
            ms.push_back(make_pair(temperatures[i], i));
        }
        while(!ms.empty())
        {
            res[ms.back().second] = 0;
            ms.pop_back();
        }
        return res;
    }
};
