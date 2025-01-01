// class Solution {
// public:
//     int maxScore(string s) {
//         int mr = 0;
//         for(int i=0;i<s.length();i++){
//             int a = 0;
//             for(int j=0;j<=i;j++){
//                 if(s[j]=='0'){
//                     a++;
//                 }
//             }

//             for(int j=i+1;j<s.length();j++){
//                 if(s[j]=='1'){
//                     a++;
//                 }
//             }
//             mr = max(mr,a);
//         }
//         return mr;
//     }
// };
class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            int curr = 0;
            for (int j = 0; j <= i; j++) {
                if (s[j] == '0') {
                    curr++;
                }
            }
            
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == '1') {
                    curr++;
                }
            }
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};