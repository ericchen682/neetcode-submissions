class Solution {
public:
    bool isPalindrome(string s) {
        string ns;
        for(int i = 0; i < s.size(); i++)
        {
            if(isalnum(s[i])) ns+=tolower(s[i]);
        }
        for(int i = 0; i < ns.size()/2; i++)
        {
            if(ns[i] != ns[ns.size()-1-i]) return false;
        }
        return true;
    }
};
