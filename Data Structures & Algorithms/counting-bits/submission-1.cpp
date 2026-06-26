class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        int curr = 1;
        for(int i = 1; i <= n; i++)
        {
            if(i >= curr*2)
                curr *= 2;
            if(i == curr)
                res.push_back(1);
            else
                res.push_back(1 + res[i % curr]);
        }
        return res;
        // 0 - 0 - 0
        // 1 - 1 - 1
        // 2 - 10 - 1
        // 3 - 11 - 2
        // 4 - 100 - 1
        // 5 - 101 - 2
        // 6 - 110 - 2
        // 7 - 111 - 3
        // 8 - 1000 - 1
        // 9 - 1001 - 2
        // 10 - 1010 - 2
        // 11 - 1011 - 3
        // 12 - 1100 - 2
        // 13 - 1101 - 3
        // 14 - 1110 - 4
        // 15 - 1111 - 5
        // 16 - 10000 - 1
        // 17 - 2
        // 18 -
        
        // every factor of 2 you memoize
        // say we are past 16
        // then our res is 1 + res[num%16]

        // 0 -> 1 -> 1 -> 2 -> 
        // 1 -> 2 -> 2 -> 3 -> 
        // 1 -> 2 -> 2 -> 3 -> 
        // 2 -> 2 -> 3 -> 4 -> 5

    }
};
