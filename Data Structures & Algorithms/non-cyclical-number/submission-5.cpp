class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(fast != 1 && slow != 1)
        {
            int temp = 0;
            while(slow != 0)
            {
                temp += (slow%10)*(slow%10);
                slow /= 10;
            }
            slow = temp;
            temp = 0;
            while(fast != 0)
            {
                temp += (fast%10)*(fast%10);
                fast /= 10;
            }
            fast = temp;
            temp = 0;
            while(fast != 0)
            {
                temp += (fast%10)*(fast%10);
                fast /= 10;
            }
            fast = temp;
            if(fast == slow && fast != 1)
                return false;
        }
        return true;
    }
};
