class Solution {
public:
    int countSubstrings(string s) {
        // a substr is a palindrome iff the smaller substring within it is a palindrome
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            // 1 letter case
            res++;
            for(int j = 1; j < s.size(); j++)
            {
                if(i + j >= s.size() || i - j < 0 || s[i + j] != s[i - j])
                    break;
                res++;
            }

            // 2 letter case;
            for(int j = 0; j < s.size(); j++)
            {
                if(i + j + 1 >= s.size() || i - j < 0 || s[i + j + 1] != s[i-j])
                    break;
                res++;
            }
        }
        return res;
    }
};
