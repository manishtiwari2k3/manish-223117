class Solution {
public:
    // const int mod = 1e9+7;
    vector<int> pse (vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nse (vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long sumSubarraymin(vector<int>& nums){
        int n = nums.size();
        long long minsum = 0;
        vector<int>psei = pse(nums);
        vector<int>nsei = nse(nums);

        for(int i=0;i<n;i++){
            int left = (psei[i]==-1) ? i+1  : i-psei[i];
            int right = (nsei[i]==n) ? n-i  : nsei[i] - i;
           minsum = (minsum + (1LL * left * right  * nums[i]) ) ;
        }
        return minsum;
    }
    vector<int> pge (vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nge (vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long sumSubarraymax(vector<int>& nums){
        int n = nums.size();
        long long maxsum = 0;
        vector<int>pgei = pge(nums);
        vector<int>ngei = nge(nums);
        for(int i=0;i<n;i++){
            int left = (pgei[i]==-1) ? i+1  : i-pgei[i];
            int right = (ngei[i]==n) ? n-i  : ngei[i] - i;
            maxsum = (maxsum + (1LL * left * right  * nums[i]) );
        }
        return maxsum;
        
    }
    long long subArrayRanges(vector<int>& nums) {
        long long maxsum = sumSubarraymax(nums);
        long long minsum = sumSubarraymin(nums);

        return (maxsum-minsum);
        
    }
};