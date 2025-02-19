class Solution {
public:
    bool isPair(char i,char l){
        return (l=='(' && i==')') || (l=='{' && i=='}') || (l=='[' && i==']');
    }
    bool isValid(string s) {
        stack <char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(!st.empty()){
                    char l = st.top();
                    if(isPair(s[i],l)){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        } 
        return st.empty();
    }
};