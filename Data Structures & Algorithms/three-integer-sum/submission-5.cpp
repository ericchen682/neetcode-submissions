class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i = 0;
        while(i < nums.size()-2)
        {
            int l = i+1;
            int r = nums.size()-1;
            while(l < r)
            {
                if(nums[i] + nums[l] + nums[r] == 0) res.push_back({nums[i], nums[l], nums[r]});
                if(nums[i] + nums[l] + nums[r] > 0)
                {
                    r--;
                    while(r > l && nums[r] == nums[r+1]) r--;
                }
                else
                {
                    l++;
                    while(r > l && nums[l] == nums[l-1]) l++;
                }
            }
            i++;
            while(i < nums.size() && nums[i] == nums[i-1]) i++;
        }
        return res;
    }
};
