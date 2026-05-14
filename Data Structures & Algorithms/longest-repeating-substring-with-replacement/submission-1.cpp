class Solution {
public:
    int characterReplacement(string s, int k) {
        int chars[26] = {};
        int res = 0;
        int l = 0;
        int maxApp = 0;
        for(int i = 0; i < s.size(); i++)
        {
            chars[s[i]-'A']++;
            maxApp = max(maxApp, chars[s[i]-'A']);
            while(maxApp + k < i-l+1)
            {
                chars[s[l]-'A']--;
                if(chars[s[l]-'A'] == maxApp-1)
                {
                    maxApp = 0;
                    for(int j = 0; j < 26; j++)
                    {
                        maxApp = max(maxApp, chars[j]);
                    }
                }
                l++;
            }
            res = max(res, i-l+1);
        }
        return res;
    }
};
