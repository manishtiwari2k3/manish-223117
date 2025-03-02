class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n = num.size();
        // if(k>0){
           for(int i=0;i<n;i++){
                while(!st.empty() && st.top()-'0'>num[i]-'0' && k>0){
                    st.pop();
                    k--;
                }
                    st.push(num[i]);
            }
        // }
            while(k>0){
                st.pop();
                k--;
            }
            string ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            while(ans.size()!=0 && ans.back()=='0'){
                ans.pop_back();
            }
            if(ans.empty()){
                return "0";
            }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};