class Solution {
public:
    vector<int>pse(vector<int>& heights){
        int n = heights.size();
        vector<int>ans(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>nse(vector<int>& heights){
        int n = heights.size();
        vector<int>ans(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> psei = pse(heights);
        vector<int> nsei = nse(heights);
        int ans = 0;
        for(int i=0;i<n;i++){
            int left = psei[i];
            int right = nsei[i];
            ans = max(ans,heights[i]*(right-left-1));
        }
        return ans;
    }
};