// class Solution {
// public:
//     int solve(int i, int j, vector<vector<int>>& grid,
//               vector<vector<int>>& dp) {
//         if (i >= grid.size() || j >= grid[0].size()) return 0;
//         if (grid[i][j] == 0) return 0;

//         if (dp[i][j] != -1) return dp[i][j];

//         int right = solve(i, j + 1, grid, dp);
//         int diagonal = solve(i + 1, j + 1, grid, dp);
//         int below = solve(i + 1, j, grid, dp);

//         return dp[i][j] = 1 + min(right, min(diagonal, below));
//     }

//     int countSquares(vector<vector<int>>& grid) {
//         int ans = 0;
//         vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
//                 ans += solve(i, j, grid, dp);
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) {
                    dp[i + 1][j + 1] =
                        min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
                    ans += dp[i + 1][j + 1];
                }
            }
        }
        return ans;
    }
};