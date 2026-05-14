class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> rects;
        heights.push_back(0);
        int res = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            while(!rects.empty() && heights[rects.top()] > heights[i])
            {
                int h = heights[rects.top()];
                rects.pop();
                int w = i;
                if(!rects.empty())
                    w -= rects.top()+1;
                res = max(res, w*h);
            }
            rects.push(i);
        }
        return res;
    }
};
