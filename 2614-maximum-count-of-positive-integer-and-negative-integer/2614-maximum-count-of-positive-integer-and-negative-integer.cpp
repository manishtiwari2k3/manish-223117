class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cn = 0;
        int cp = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                cp++;
            }
            else if(nums[i]<0){
                cn++;
            }
        }
        return max(cp,cn);
    }
};