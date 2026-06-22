class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // consider each 0 as a barrier
        // find max subarray
        int res = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];
            res = max(res, curr);
            for(int j = i + 1; j < nums.size(); j++)
            {
                curr *= nums[j];
                res = max(res, curr);
            }
        }
        return res;
    }
};
