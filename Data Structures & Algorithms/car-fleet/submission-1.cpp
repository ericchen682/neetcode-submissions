class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 0;
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++)
        {
            cars.push_back(make_pair(position[i], speed[i]));
        }
        sort(cars.begin(), cars.end());
        long double time = 0;
        for(int i = cars.size()-1; i >= 0; i--)
        {
            long double currTime = target-cars[i].first;
            currTime /= cars[i].second;
            if(currTime > time)
            {
                time = currTime;
                res++;
            }
        }
        return res;
    }
};
