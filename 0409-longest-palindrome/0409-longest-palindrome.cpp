class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        vector <int> lower(26,0);
        vector <int> upper(26,0);
        int count = 0;
        int odd = 0;
        for(int i=0;i<n;i++){
            if(s[i]>='a'){
                lower[s[i]-'a']++;
            }
            else{
                upper[s[i]-'A']++;
            }
        }

        // 
        for(int i=0;i<26;i++){
            if(lower[i]%2==0){
                count = count+lower[i];
            }
            else{
                odd = 1;
                count = count+lower[i]-1;
            }
            if(upper[i]%2==0){
                count = count+upper[i];
            }
            else{
                odd = 1;
                count = count+upper[i]-1;
            }
          }   
        //   if(odd=1){
        //     count++;
        //   }
    return count+odd;
    }
};