class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lfx[n+1], rfx[n+1];
        lfx[0] = 0;
        for(int i = 0; i < n; i++)
        {
            lfx[i+1] = max(lfx[i], height[i]);
        }
        rfx[n] = 0;
        for(int i = n-1; i >= 0; i--)
        {
            rfx[i] = max(rfx[i+1], height[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res += max(min(lfx[i], rfx[i+1])-height[i], 0);
        }
        return res;
    }
};
