class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0 , r = 0 , maxlen = 0 , maxf = 0;
        int hash[26] = {0};
        while(r<s.length()){
            hash[s[r] - 'A']++;
            maxf = max(maxf,hash[s[r] - 'A']);
            if((r-l+1)-maxf>k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxf<=k){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int l = 0 , r = 0 , maxlen = 0, maxf = 0;
//         int hash[26] = {0};
//         while(r<s.size()){
//             hash[s[r]-'A']++;
//             maxf = max(maxf,hash[s[r]-'A']);
//             if((r-l+1)-maxf>k){
//                 hash[s[l]-'A']--;
//                 maxf = 0;
//                 for(int i=0;i<26;i++){
//                     maxf = max(maxf,hash[i]);
//                 }
//                 l++;
//             }
//             if((r-l+1)-maxf<=k){
//                 maxlen= max(maxlen,r-l+1);
//             }
//             r++;
//         }
//         return maxlen;
//     }
// };
// // class Solution {
// // public:
// //     int characterReplacement(string s, int k) {
// //         int l = 0 , r = 0 , maxlen = 0, maxf = 0;
// //         int hash[26] = {0};
// //         while(r<s.size()){
// //             hash[s[r]-'A']++;
// //             maxf = max(maxf,hash[s[r]-'A']);
// //             while((r-l+1)-maxf>k){
// //                 hash[s[l]-'A']--;
// //                 maxf = 0;
// //                 for(int i=0;i<26;i++){
// //                     maxf = max(maxf,hash[i]);
// //                 }
// //                 l++;
// //             }
// //             if((r-l+1)-maxf<=k){
// //                 maxlen= max(maxlen,r-l+1);
// //             }
// //             r++;
// //         }
// //         return maxlen;
// //     }
// // };


// // // class Solution {
// // // public:
// // //     int characterReplacement(string s, int k) {
// // //         int maxlen = 0;
// // //         for(int i=0;i<s.length();i++){
// // //             int hash[26] = {0};
// // //             int maxf = 0;
// // //             for(int j=i;j<s.length();j++){
// // //                 hash[s[j]-'A']++;
// // //                 maxf = max(maxf,hash[s[j]-'A']);
// // //                 int changes = (j-i+1)-maxf;
// // //                 if(changes<=k){
// // //                     maxlen = max(maxlen,j-i+1);
// // //                 }
// // //                 else{
// // //                     break;
// // //                 }
// // //             }
// // //         }
// // //         return maxlen;
// // //     }
// // // };