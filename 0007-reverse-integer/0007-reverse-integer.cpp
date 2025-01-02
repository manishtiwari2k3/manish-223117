class Solution {
public:
    int reverse(int x) {
        int temp = x;
        long ans = 0;
        while(temp){
        int digit = temp%10;
        ans = ans*10+digit;
        temp = temp/10;
        }
        if(ans>INT_MAX || ans<INT_MIN){
            return 0;
        }
    return ans;
    }
};