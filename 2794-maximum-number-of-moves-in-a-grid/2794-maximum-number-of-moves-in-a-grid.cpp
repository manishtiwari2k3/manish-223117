// class Solution {
// public:
//     const int dirs[3] = {-1, 0, 1};

//     int maxMoves(vector<vector<int>>& grid) {
//         int M = grid.size(), N = grid[0].size();

//         queue<vector<int>> q;
//         vector<vector<int>> vis(M, vector<int>(N, 0));
//         for (int i = 0; i < M; i++) {
//             vis[i][0] = 1;
//             q.push({i, 0, 0});
//         }

//         int maxMoves = 0;
//         while (!q.empty()) {
//             int sz = q.size();

//             while (sz--) {
//                 vector<int> v = q.front();
//                 q.pop();
//                 int row = v[0] , col = v[1], count = v[2];

//                 maxMoves = max(maxMoves, count);

//                 for (int dir : dirs) {
//                     int newRow = row + dir, newCol = col + 1;
//                     if (newRow >= 0 && newCol >= 0 && newRow < M &&
//                         newCol < N && !vis[newRow][newCol] &&
//                         grid[row][col] < grid[newRow][newCol]) {
//                         vis[newRow][newCol] = 1;
//                         q.push({newRow, newCol, count + 1});
//                     }
//                 }
//             }
//         }

//         return maxMoves;
//     }
// };





class Solution {
public:
    const int dirs[3] = {-1, 0, 1};

    int DFS(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& dp) {
        int M = grid.size(), N = grid[0].size();
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int maxMoves = 0;
        for (int dir : dirs) {
            int newRow = row + dir, newCol = col + 1;
            if (newRow >= 0 && newCol >= 0 && newRow < M && newCol < N &&
                grid[row][col] < grid[newRow][newCol]) {
                maxMoves = max(maxMoves, 1 + DFS(newRow, newCol, grid, dp));
            }
        }

        return dp[row][col] = maxMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();

        vector<vector<int>> dp(M, vector<int>(N, -1));

        int maxMoves = 0;
        for (int i = 0; i < M; i++) {
            int movesRequired = DFS(i, 0, grid, dp);

            maxMoves = max(maxMoves, movesRequired);
        }

        return maxMoves;
    }
};