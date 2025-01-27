class Solution {
public:
    bool checkValidString(string s) {
        int low =0;
        int high =0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                low++;
                high++;
            }
            else if(s[i]==')'){
                low = max(low-1,0);
                high--;
            }
            else{
                low = max(low-1,0);
                high++;
            }
            if(high<0){
                return false;
            }
        }
        return (low==0);
    }
};

// class Solution {
// public:
//     bool func(string &s , int ind , int cnt){
//         if(cnt<0){
//             return false;
//         }
//         if(ind == s.length()){
//             return (cnt == 0); //if cnt == 0 return true else return false
//         }
//         if(s[ind] == '('){
//             return func(s , ind+1 ,cnt+1);
//         }
//         else if(s[ind] == ')'){
//             return func(s , ind+1 ,cnt-1);
//         }
//         else{
//             return (func(s , ind+1 ,cnt+1) ||func(s , ind+1 ,cnt-1) || func(s , ind+1 ,cnt));
//         }
//     }
//     bool checkValidString(string s) {
//         int ind  = 0;
//         return func(s , ind , 0);
//     }
// };