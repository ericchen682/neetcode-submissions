class Solution {
public:
    int maxArea(vector<int>& heights) {
        // pick i, j
        // then water = (j-i)*min(height[j], height[i])
        int res = 0;
        // is greedy 2 ptr always the right soln?
        // yes
        int l = 0, r = heights.size()-1;
        while(l < r)
        {
            res = max(res, (r-l)*min(heights[l], heights[r]));
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return res;
    }
};
