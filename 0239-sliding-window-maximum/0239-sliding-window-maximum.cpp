class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque <int> dq;
        vector <int> ls;
        for(int i=0;i<n;i++){
            if(!dq.empty()&&dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ls.emplace_back(nums[dq.front()]);
            }
        }
        return ls;
    }
};

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ls;
//         for(int i=0;i<n-k+1;i++){
//             int maxi = nums[i];
//             for(int j=i;j<i+k;j++){
//                 maxi = max(nums[j],maxi);
//             }
//             ls.emplace_back(maxi);
//         }
//         return ls;
//     }
// };