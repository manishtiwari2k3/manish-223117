class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> preS(n,0);
        preS[0] = height[0];
        for(int i=1;i<n;i++){
            preS[i] = max(preS[i-1],height[i]);
        }
        vector <int> posS(n,0);
        posS[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            posS[i] = max(posS[i+1],height[i]);
        }

        int total = 0;
        for(int i=0;i<n;i++){
            int lm = preS[i] ;
            int rm = posS[i] ;
            if(height[i]<preS[i] && height[i]<posS[i]){
                total+= min(lm,rm)-height[i];
            }
        }
        return total;
    }
};