class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx = 0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                maxx++;
            }
            else if(nums[i]!=1){
                maxi = max(maxi,maxx);
                maxx = 0;
            }
        }
        return max(maxi,maxx);
    }
};