class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = ((n+1)*n)/2;
        for(auto num : nums)
        {
            res -= num;
        }
        return res;
    }
};
