class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // two ptr problem
        // hashmap
        unordered_map<char, bool> m;
        int l = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            while(m[s[i]])
            {
                m[s[l]] = false;
                l++;
            }
            m[s[i]] = true;
            res = max(res, i-l+1);
        }
        return res;
    }
};
