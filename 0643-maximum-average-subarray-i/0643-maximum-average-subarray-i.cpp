class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()==1){
            return (double) nums[0];
        }
        double maxavg = 0 ;
        int sum = 0;
        for(int i=0;i<k;i++){
            sum = sum + nums[i];
        }
        maxavg = (double) sum/k;
        for(int i=k;i<nums.size();i++){
            sum = sum + nums[i]-nums[i-k];
            if(((double)sum/k)>maxavg){
                maxavg = (double) sum/k;
            }
        }
        
        
        return maxavg;
    }
};