class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // store sorted strings
        vector<vector<string>> res;
        vector<string> sorted;
        string str = strs[0];
        sort(str.begin(), str.end());
        sorted.push_back(str);
        res.push_back({ strs[0] });
        bool newWord;
        for(int i = 1; i < strs.size(); i++)
        {
            str = strs[i];
            sort(str.begin(), str.end());
            newWord = true;
            for(int j = 0; j < sorted.size(); j++)
            {
                if(str == sorted[j])
                {
                    res[j].push_back(strs[i]);
                    newWord = false;
                }
            }
            if(newWord)
            {
                sorted.push_back(str);
                res.push_back({ strs[i] });
            }
        }
        return res;
    }
};
