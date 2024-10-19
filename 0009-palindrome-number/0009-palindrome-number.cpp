class Solution {
public:
    bool isPalindrome(int x) {
        long n = 0;
        long originalX = x;
        if(x==0){
            return true;
        }
        if(x<0 || (x%10==0 && x!=0)){
            return false;
        }
        while(x>0){
            n = (n*10)+(x%10);
            x = x/10;
        }
        if(n==originalX){
            return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         int n = 0;
//         int orN = x;
//         if(x<0){
//             x = x*(-1);
//         }
//         while(x){
//             n = (n*10)+(x%10);
//             x = x/10;
//         }
//         if(x<0){
//             n = n*(-1);
//         }
//         if(n!=orN){
//             return false;
//         }
//         return true;
//     }
// };