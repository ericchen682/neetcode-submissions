class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        // handle case of first incl. but not last (circle)
        for(int i = 0; i < n - 1; i++)
        {
            if (i + 1 < n - 1)
                dp[i + 1] = max(dp[i], dp[i + 1]);
            if (i + 2 < n - 1)
                dp[i + 2] = max(dp[i + 2], dp[i] + nums[i + 2]);
        }
        int r1 = dp[n-2];

        // handle case of last incl. but not first (circle)
        vector<int> dp2(n, 0);
        dp2[1] = nums[1];
        dp2[2] = nums[2];
        for(int i = 1; i < n; i++)
        {
            if (i + 1 < n)
                dp2[i + 1] = max(dp2[i], dp2[i + 1]);
            if (i + 2 < n)
                dp2[i + 2] = max(dp2[i + 2], dp2[i] + nums[i + 2]);
        }
        int r2 = dp2[n-1];

        cout << r1 << ' ' << r2 << '\n';
        return max(r1, r2);
    }
};
