class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }
        bool sign = true;
        if(dividend<0 && divisor>0){
            sign = false;
        }
        else if(dividend>=0 && divisor<0){
            sign = false;
        }
        long n = abs(dividend);
        long d = abs(divisor);
        long quotient = 0;
        while(n>=d){
            int cnt = 0;
            while(n>=d<<(cnt+1)){
                cnt++;
            }
            quotient = quotient+(1<<cnt);
            n = n-(d<<cnt);
        }
        if(quotient==(1<<31) && sign){
            return INT_MAX;
        }
        if(quotient==(1<<31) && !sign){
            return INT_MIN;
        }
        return sign ? quotient : -quotient;
    }
};

// class Solution {
// public:
//     int divide(int dividend, int divisor) {
// //         class Solution {
// // public:
// //     int divide(int dividend, int divisor) {
// //         int cnt  = 0;
// //         int sum = 0;
// //         while((sum+divisor)>=dividend){
// //             cnt++;
// //             sum = sum + divisor;
// //         }
// //         return cnt;
// //     }
// // };




//         if(dividend == divisor){
//             return 1;
//         }
//         bool sign = true;
//         if(dividend<0 && divisor>0){
//             sign = false;
//         }
//         else if(dividend>=0 && divisor<0){
//             sign = false;
//         }
//         long n = abs(dividend);
//         long d = abs(divisor);
//         // divisor = abs(divisor);
//         long quotient = 0;
//         while(n>=d){
//             int cnt = 0;
//             while(n>=(d<<cnt+1)){
//                 cnt++;
//             }
//             quotient = quotient+(1<<cnt);
//             n = n - (d<<cnt);
//         }
//         if(quotient==(1<<31) && sign){
//             return INT_MAX;
//         }
//         if(quotient==(1<<31) && !sign){
//             return INT_MIN;
//         }
//         return sign ? quotient : -quotient;
//     }
// };