class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int chars[26] = {};
        int taskCount = tasks.size();
        int res = taskCount;
        int maxChars = 0;
        for(int i = 0; i < taskCount; i++)
        {
            maxChars = max(maxChars, ++chars[tasks[i]-'A']);
        }
        int maxCharCount = 0;
        for(int i = 0; i < 26; i++)
        {
            if(chars[i] == maxChars) maxCharCount++;
        }
        int gapMax = maxChars - 1;
        gapMax *= (n + 1);
        gapMax += maxCharCount;
        return max(res, gapMax);
        // determine max # of tasks and how many of max # of tasks there are
        // if total tasks/max # tasks 
    }
};
