class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs = nums[0];
        int curs = nums[0];
        for(int i=1;i<nums.size();i++){
            curs = max(nums[i],curs+nums[i]);
            maxs = max(maxs,curs);
        }
        return maxs;
    }
};

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxs = INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             int cursum = 0;
//             for(int j=i;j<nums.size();j++){
//                 cursum = cursum+nums[j];
//                 maxs = max(maxs,cursum);
//             }
//         }
//         return maxs;
//     }
// };