class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix multiplication
        int n = nums.size();
        int lfx[n+1];
        int rfx[n+1];
        lfx[0] = 1;
        for(int i = 0; i < n; i++)
        {
            lfx[i+1] = lfx[i]*nums[i];
        }
        rfx[n] = 1;
        for(int i = n-1; i >= 0; i--)
        {
            rfx[i] = rfx[i+1]*nums[i];
        }
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            res.push_back(lfx[i]*rfx[i+1]);
        }
        return res;
    }
};
