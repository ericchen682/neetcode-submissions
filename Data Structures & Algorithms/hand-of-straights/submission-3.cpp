class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // sort cards in order
        // min must be the start of a straight
        map<int, int> cards;
        for(int i = 0; i < hand.size(); i++)
        {
            cards[hand[i]]++;
        }
        sort(hand.begin(), hand.end());
        for(int i = 0; i < hand.size(); i++)
        {
            if(cards[hand[i]] == 0) continue;
            else
            {
                for(int j = 1; j < groupSize; j++)
                {
                    cards[hand[i]+j] -= cards[hand[i]];
                    if(cards[hand[i]+j] < 0) return false;
                }
                cards[hand[i]] = 0;
            }
        }
        return true;
    }
};
