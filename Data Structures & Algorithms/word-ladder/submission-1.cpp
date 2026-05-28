class Solution {
public:
    bool oneDiff(string a, string b)
    {
        int diffs = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i]) diffs++;
        }
        return diffs == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // if endword is beginword
        if(beginWord == endWord) return 0;

        // check if endword is in list
        bool isReachable = false;
        int tind = -1;
        for(int i = 0; i < wordList.size(); i++)
        {
            if(wordList[i] == endWord)
            {
                isReachable = true;
                tind = i;
            }
        }
        if(!isReachable) return 0;

        // we want to bfs from beginword -> endword
        int n = wordList.size();
        vector<bool> vis(n, false);
        queue<pair<int, int>> bfs;
        bfs.push({-1, 0});
        while(!bfs.empty())
        {
            int ind = bfs.front().first;
            int dist = bfs.front().second;
            bfs.pop();

            if(ind == tind) return dist+1;
            // handle beginword case
            if(ind == -1)
            {
                for(int i = 0; i < n; i++)
                {
                    if(oneDiff(beginWord, wordList[i]))
                    {
                        vis[i] = true;
                        bfs.push({i, 1});
                    }
                }
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    if(vis[i]) continue;
                    if(oneDiff(wordList[ind], wordList[i]))
                    {
                        vis[i] = true;
                        bfs.push({i, dist+1});
                    }
                }
            }
        }
        return 0;
    }
};
