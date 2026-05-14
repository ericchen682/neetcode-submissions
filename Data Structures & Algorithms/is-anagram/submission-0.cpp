class Solution {
public:
    bool isAnagram(string s, string t) {
        int sa[26] = {};
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++)
        {
            sa[s[i]-'a']++;
            sa[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++)
        {
            if(sa[i]) return false;
        }
        return true;
    }
};
