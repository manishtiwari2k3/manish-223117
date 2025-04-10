class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt0++;
            }
            else if(nums[i]==1){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        int i = 0;
        while(cnt0){
            nums[i] = 0;
            cnt0--;
            i++;
        }
        while(cnt1){
            nums[i] = 1;
            cnt1--;
            i++;
        }
        while(cnt2){
            nums[i] = 2;
            cnt2--;
            i++;
        }
        
    }
};