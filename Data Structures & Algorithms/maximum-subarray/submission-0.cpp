class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(curr < 0)
                curr = 0;
            curr += nums[i];
            res = max(res, curr);
        }
        return res;
    }
};
