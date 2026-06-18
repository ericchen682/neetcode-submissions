class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        if(n == 1) return nums[0];
        arr[0] = nums[0];
        arr[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++)
        {
            arr[i] = max(arr[i-1], arr[i-2] + nums[i]);
        }
        return max(arr[n-1], arr[n-2]);
    }
};
