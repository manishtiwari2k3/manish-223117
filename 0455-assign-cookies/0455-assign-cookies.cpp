class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int count = 0;
        int l =0 , r=0;
        while(l<n && r<m){
            if(s[r]>=g[l]){
                count++;
                l++;
            }
            r++;         
        }
    return count;
    }
};