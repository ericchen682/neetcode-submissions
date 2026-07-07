class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        // in increasing order return a < b
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort them by start point
        // if 2 intervals overlap, always remove the one with the later end point
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        int lastEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(lastEnd > intervals[i][0])
            {
                res++;
                lastEnd = min(lastEnd, intervals[i][1]);
            }
            else
            {
                lastEnd = max(lastEnd, intervals[i][1]);
            }
        }
        return res;
    }
};
