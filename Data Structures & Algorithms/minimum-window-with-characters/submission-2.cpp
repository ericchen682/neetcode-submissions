class Solution {
public:
    string minWindow(string s, string t) {
        int scnt[100] = {};
        int tcnt[100] = {};
        for(int i = 0; i < t.size(); i++)
        {
            tcnt[t[i]-'A']++;
        }
        int resSize = INT_MAX;
        int fl, fr;
        int l = 0, r = 0;
        int have = 0;
        int need = t.size();
        while(r < s.size())
        {
            scnt[s[r]-'A']++;
            if(scnt[s[r]-'A'] <= tcnt[s[r]-'A']) have++;
            r++;
            if(have == need)
            {
                while(have == need)
                {
                    scnt[s[l]-'A']--;
                    if(scnt[s[l]-'A'] < tcnt[s[l]-'A'])
                    {
                        have--;
                        if(r-l < resSize)
                        {
                            resSize = r-l;
                            fr = r;
                            fl = l;
                        }
                    }
                    l++;
                }
            }
        }
        if(resSize == INT_MAX) return "";
        string res = s.substr(fl, resSize);
        return res;
    }
};
