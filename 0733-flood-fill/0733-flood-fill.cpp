class Solution {
public:
    void dfs(vector<vector<int>>& image , vector<vector<int>>&ans , int delrow[] , int  delCol[] , int color , int iniColor , int row, int col){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=color){
                dfs(image , ans , delrow , delCol , color , iniColor , nrow , ncol);
            } 
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int iniColor = image[sr][sc];
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(image , ans , delRow , delCol , color , iniColor , sr , sc);
        return ans;
    }
};