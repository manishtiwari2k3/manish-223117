class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long ans = 0;
        if(temp<0){
            return false;
        }
        while(temp){
            int digit = temp%10;
            ans = ans*10+digit;
            temp=temp/10;
        }
        if(ans==x){
            return true;
        }
    return false;
    }
};