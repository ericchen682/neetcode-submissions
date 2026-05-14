class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target) 
                return mid;
            if(nums[mid] > target)
                r = mid-1;
            else
                l = mid+1;
        }
        if(l < nums.size() && nums[l] == target) return l;
        if(r >= 0 && nums[r] == target) return r;
        return -1;
    }
};
