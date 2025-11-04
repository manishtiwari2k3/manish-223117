class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());

        for(int i=0;i<nums.size();i++){
            int toFind = target - arr[i].first;
            int low = i+1;
            int high = nums.size()-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(arr[mid].first == toFind){
                    return {arr[i].second,arr[mid].second};
                }
                else if(arr[mid].first<toFind){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return {-1};
    }
};