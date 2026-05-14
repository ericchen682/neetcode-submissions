class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(int i = 0; i < strs.size(); i++)
        {
            res+=strs[i];
            res+='\n';
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string curr;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '\n')
            {
                res.push_back(curr);
                curr = "";
            }
            else
            {
                curr+=s[i];
            }
            i++;
        }
        // res.push_back(curr);
        return res;
    }
};
