class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> prefixMax(n,0);
        prefixMax[0] = height[0];
        for(int i=1;i<n;i++){
            // if(height[i]>prefixMax[i-1]){
            //     prefixMax[i] = height[i];
            // }
            prefixMax[i] = max(height[i],prefixMax[i-1]);
        }
        vector <int> suffixMax(n,0);
        suffixMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            // if(height[i]>suffixMax[i+1]){
            //     suffixMax[i] = height[i];
            // }
            suffixMax[i] = max(height[i],suffixMax[i+1]);
        }
        int total = 0;
        for(int i=0;i<n;i++){
            int lmax = prefixMax[i];
            int rmax = suffixMax[i];
            if(height[i]<lmax && height[i]<rmax){
                total += min(lmax,rmax)-height[i];
            }
        }
        return total;
    }
};