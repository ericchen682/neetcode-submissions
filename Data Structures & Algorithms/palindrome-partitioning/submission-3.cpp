class Solution {
public:
    vector<vector<string>> res;
    void solve(string s, vector<string> curr, int l, int r)
    {
        if (r >= s.size()) return;
        solve(s, curr, l, r+1);

        // check if l, r is palindrome
        int tl = l;
        int tr = r;
        while(tl < tr)
        {
            if(s[tl] != s[tr])
                return;
            tl++;
            tr--;
        }
        curr.push_back(s.substr(l, r-l+1));
        if(r == s.size()-1) 
            res.push_back(curr);
        else
            solve(s, curr, r+1, r+1);
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s, temp, 0, 0);
        return res;
    }
};
