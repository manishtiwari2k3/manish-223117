class Solution {
public:
    bool isP(vector <int>& nums, int p){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==p){
                return true;
            }
        }
        return false;
    }
    int missingNumber(vector<int>& nums) {
        for(int i=0;i<=nums.size();i++){
            if(isP(nums,i)==false){
                return i;
            }
        }
        return -1;
    }
};