class Solution {
public:
    void markRow(vector<vector<int>>& matrix, int m){
        int n = matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[m][i]!=0){
                 matrix[m][i]='a';
            }  
        }
    }
    void markCol(vector<vector<int>>& matrix, int m){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            if(matrix[i][m]!=0){
                 matrix[i][m]='a';
            } 
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    markRow(matrix , i);
                    markCol(matrix , j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='a'){
                    matrix[i][j] = 0 ;
                }
            }
        }
    }
};