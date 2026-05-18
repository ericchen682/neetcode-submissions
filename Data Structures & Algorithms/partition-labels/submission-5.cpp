class Solution {
public:
    vector<int> partitionLabels(string s) {
        // split string into as many substring as possible
        // ensure that each letter appears in at most one substring

        // solution is to:
        // create intervals of where each letter starts and ends
        // merge overlapping intervals
        // number of final intervals is result

        vector<pair<int, int>> intervals;
        map<char, pair<int, int>> m;

        for(int i = 0; i < s.size(); i++)
        {
            if(m[s[i]].first == 0)
                m[s[i]].first = i+1;
            m[s[i]].second = i+1;
        }

        for(auto const& [key, value] : m)
        {
            intervals.push_back(value);
        }

        sort(intervals.begin(), intervals.end());

        // now merge intervals
        int l = intervals[0].first;
        int r = 0;
        vector<int> res;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(r < intervals[i].first)
            {
                if(r != 0)
                {
                    res.push_back(r-l+1);
                    l = intervals[i].first;
                }
            }
            r = max(r, intervals[i].second);
        }
        if(l != INT_MAX) res.push_back(r-l+1);
        return res;
    }
};
