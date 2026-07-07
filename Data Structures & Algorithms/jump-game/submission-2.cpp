class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        vis[0] = true;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i]) continue;
            for(int j = 1; j <= nums[i] && i + j < n; j++)
            {
                vis[i + j] = true;
            }
        }
        return vis[n-1];
    }
};
