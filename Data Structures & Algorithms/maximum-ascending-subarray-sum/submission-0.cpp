class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int curr = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            res = max(res, curr);
            if(nums[i] <= nums[i-1])
                curr = 0;
            curr += nums[i];
        }
        res = max(res, curr);
        return res;
    }
};