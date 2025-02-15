class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <int> rows(n,0);
        vector <int> cols(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rows[i]||cols[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

// class Solution {
// public:
//     void markCol(int j,vector<vector<int>>& matrix){
//         int n = matrix.size();
//         for(int i=0;i<n;i++){
//             if(matrix[i][j]!=0){
//                 matrix[i][j]='a';
//             }
//         }
//     }
//     void markRow(int i,vector<vector<int>>& matrix){
//         int m = matrix[0].size();
//         for(int j=0;j<m;j++){
//             if(matrix[i][j]!=0){
//                 matrix[i][j]='a';
//             }
//         }
//     }
//     void setZeroes(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//     int m = matrix[0].size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==0){
//                     markCol(j,matrix);
//                     markRow(i,matrix);
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]=='a'){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//     }
// };