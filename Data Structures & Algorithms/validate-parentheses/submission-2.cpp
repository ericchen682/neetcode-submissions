class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;
        map<char, char> m;
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                chars.push(s[i]);
            }
            else
            {
                if(chars.empty()) return false;
                if(chars.top() != m[s[i]]) return false;
                chars.pop();
            }
        }
        return chars.empty();
    }
};
