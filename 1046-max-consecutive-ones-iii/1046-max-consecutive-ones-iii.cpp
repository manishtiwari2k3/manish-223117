class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0 ;
        int l = 0 ;
        int r = 0 ;
        int zeroes = 0;
        while(r<nums.size()){
            if(nums[r]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(nums[l]==0){
                    zeroes--;
                    // l++;
                }
                l++;
            }
            if(zeroes<=k){
                int len = r-l+1;
                maxlen = max(len,maxlen);
            }
            r++;
        }
        return maxlen;
    }
};

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int maxlen = 0;
//         for(int i=0;i<n;i++){
//             int zeros = 0;
//             for(int j=i;j<n;j++){
//                 if(nums[j]==0){
//                     zeros++;
//                 }
//                 if(zeros<=k){
//                     int len = j-i+1;
//                     maxlen = max(len,maxlen);
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         return maxlen;
//     }
// };