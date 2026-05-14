class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m[nums[i]]) continue;
            m[nums[i]] = 1;
            m[nums[i]] += m[nums[i]-1] + m[nums[i]+1];
            if(m[nums[i]-1])
            {
                m[nums[i]-m[nums[i]-1]] = m[nums[i]];
            }
            if(m[nums[i]+1])
            {
                m[nums[i]+m[nums[i]+1]] = m[nums[i]];
            }
            res = max(res, m[nums[i]]);
        }
        return res;
    }
};
