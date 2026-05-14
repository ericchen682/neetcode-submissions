class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26] = {};
        for(int i = 0; i < s1.size(); i++)
        {
            arr1[s1[i]-'a']++;
        }
        int l = 0;
        int arr2[26] = {};
        for(int i = 0; i < s2.size(); i++)
        {
            arr2[s2[i]-'a']++;
            if(arr2[s2[i]-'a'] == arr1[s2[i]-'a'] && i-l+1 == s1.size()) return true;
            while(arr2[s2[i]-'a'] > arr1[s2[i]-'a'])
            {
                arr2[s2[l]-'a']--;
                l++;
            }
        }
        return false;
    }
};
