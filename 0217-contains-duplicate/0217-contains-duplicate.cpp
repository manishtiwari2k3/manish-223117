class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back(nums[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<nums.size()-1;i++){
            if(arr[i]==arr[i+1]){
                return true;
            }
        }
        return false;
    }
};