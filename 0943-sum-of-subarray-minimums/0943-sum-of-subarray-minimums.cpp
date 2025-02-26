class Solution {
public:
    vector <int> pse(vector<int>& arr){
        int n = arr.size();
        vector<int> ansp(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
            }
            if(!st.empty()){
                ansp[i] = st.top();
            }
            // else{
            //     ansp[i] = st.top();
            // }
            st.push(i);      
        }
        return ansp;
    }
    vector <int> nse(vector<int>& arr){
        int n = arr.size();
        vector<int> ansn(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
            }
            if(!st.empty()){
                ansn[i] = st.top();
            }
            // else{
            //     ansn[i] = st.top();
            // }
            st.push(i);      
        }
        return ansn;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>psei = pse(arr);
        vector<int>nsei =nse(arr);
        long long total = 0;
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            int left = (psei[i] == -1) ? i + 1 : i - psei[i];
            int right = (nsei[i] == n) ? n - i : nsei[i] - i;
            total = (total + (1LL*left*right*arr[i])%mod)%mod;
        }
        return total;
    }
};