class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool front = true;
        for(int i = digits.size()-1; i >= 0; i--)
        {
            if(!front) break;
            digits[i]++;
            front = false;
            if(digits[i] == 10)
            {
                front = true;
                digits[i] = 0;
            }
        }
        if (front)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
