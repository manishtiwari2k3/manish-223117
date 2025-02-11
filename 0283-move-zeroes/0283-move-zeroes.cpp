class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroes  = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeroes++;
            }
        }
        vector <int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
            }
        }
        while(zeroes){
            ans.push_back(0);
            zeroes--;
        }
        nums = ans;
    }
};