class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxf = 0;
        int a = 0;
        unordered_map <int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            maxf = max(maxf , count[nums[i]]);
        }
        for(int i=0;i<nums.size();i++){
            if(maxf==count[nums[i]]){
                a++;
            }
        }
        return a;
    }
};