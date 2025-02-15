class Solution {
public:
    void markCol(int j,vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            if(matrix[i][j]!=0){
                matrix[i][j]='a';
            }
        }
    }
    void markRow(int i,vector<vector<int>>& matrix){
        int m = matrix[0].size();
        for(int j=0;j<m;j++){
            if(matrix[i][j]!=0){
                matrix[i][j]='a';
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    markCol(j,matrix);
                    markRow(i,matrix);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='a'){
                    matrix[i][j]=0;
                }
            }
        }
    }
};