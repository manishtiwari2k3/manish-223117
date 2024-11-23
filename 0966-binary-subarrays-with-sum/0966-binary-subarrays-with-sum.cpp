class Solution {
public:
    int solve(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }
        int l=0 , r=0 , count=0 , sum=0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve( nums, goal-1);
    }
};

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int count = 0;
//         for(int i=0;i<nums.size();i++){
//             int sum = 0;
//             for(int j=i;j<nums.size();j++){
//                 sum = sum + nums[j];
//                 // if(sum<goal){
//                 //     count++;
//                 // }
//                 // if(sum>=goal){
//                 //     break;
//                 // }
//                 if(sum==goal){
//                     count++;
//                 } 
//             }
//         }
//         return count;
//     }
// };
