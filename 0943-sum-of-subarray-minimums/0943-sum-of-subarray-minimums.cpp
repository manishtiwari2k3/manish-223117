class Solution {
public:
    vector <int> pse(vector<int>& arr){
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector <int> nse(vector<int>& arr){
        int n = arr.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        const int mod = 1e9+7;
        vector<int>psei = pse(arr);
        vector<int>nsei = nse(arr);
        for(int i=0;i<n;i++){
            int left = (psei[i]==-1) ? i+1 : i-psei[i];
            int right = (nsei[i]==n) ? n-i : nsei[i]-i;
            total = (total+(1LL*left*right *arr[i])%mod)%mod;

        }
        return total;
    }
};