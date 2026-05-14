class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n1, n2;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+")
            {
                n1 = s.top();
                s.pop();
                n2 = s.top();
                s.pop();
                s.push(n1+n2);
                continue;
            }
            if(tokens[i] == "-")
            {
                n1 = s.top();
                s.pop();
                n2 = s.top();
                s.pop();
                s.push(n2-n1);
                continue;
            }
            if(tokens[i] == "*")
            {
                n1 = s.top();
                s.pop();
                n2 = s.top();
                s.pop();
                s.push(n1*n2);
                continue;
            }
            if(tokens[i] == "/")
            {
                n1 = s.top();
                s.pop();
                n2 = s.top();
                s.pop();
                s.push(n2/n1);
                continue;
            }
            s.push(stoi(tokens[i]));
            // cout << tokens[i][0];
        }
        return s.top();
    }
};
