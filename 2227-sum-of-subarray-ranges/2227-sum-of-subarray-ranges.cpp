class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            int smallest = nums[i];
            int largest = nums[i];
            for(int j=i;j<n;j++){
                if(nums[j]>largest){
                    largest = nums[j];
                }
                if(nums[j]<smallest){
                    smallest = nums[j];
                }
                ans = ans+(largest-smallest);
            }
        }
        return ans;
    }
};