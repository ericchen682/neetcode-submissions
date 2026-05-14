class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            r = max(r, piles[i]);
        }
        while(l <= r)
        {
            int mid = (l+r)/2;
            int ctime = 0;
            for(int i = 0; i < piles.size(); i++)
            {
                ctime += (piles[i] - 1) / mid + 1;
                if(ctime > h) break;
            }
            if(ctime > h)
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
};
