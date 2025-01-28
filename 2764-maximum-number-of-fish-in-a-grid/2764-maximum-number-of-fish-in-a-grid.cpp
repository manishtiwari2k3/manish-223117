// class Solution {
// private:
//     int calculateFishes(vector<vector<int>>& grid,
//                         vector<vector<bool>>& visited, int row, int col) {
//         if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
//             grid[row][col] == 0 || visited[row][col]) {
//             return 0;
//         }

//         visited[row][col] = true;

//         return grid[row][col] + calculateFishes(grid, visited, row, col + 1) +
//                calculateFishes(grid, visited, row, col - 1) +
//                calculateFishes(grid, visited, row + 1, col) +
//                calculateFishes(grid, visited, row - 1, col);
//     }

// public:
//     int findMaxFish(vector<vector<int>>& grid) {
//         int rows = grid.size(), cols = grid[0].size();
//         int maxFishCount = 0;

//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));

//         for (int row = 0; row < rows; row++) {
//             for (int col = 0; col < cols; col++) {
//                 if (grid[row][col] > 0 && !visited[row][col]) {
//                     maxFishCount = max(
//                         maxFishCount, calculateFishes(grid, visited, row, col));
//                 }
//             }
//         }
//         return maxFishCount;
//     }
// };


class Solution {
private:
    // Function to perform BFS and count fishes in the connected component
    int countFishes(vector<vector<int>>& grid, vector<vector<bool>>& visited,
                    int row, int col) {
        int numRows = grid.size(), numCols = grid[0].size(), fishCount = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        // Directions for exploring up, down, left, right
        vector<int> rowDirections = {0, 0, 1, -1};
        vector<int> colDirections = {1, -1, 0, 0};

        // BFS traversal
        while (!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            fishCount += grid[row][col];

            // Exploring all four directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + rowDirections[i];
                int newCol = col + colDirections[i];
                if (0 <= newRow && newRow < numRows && 0 <= newCol &&
                    newCol < numCols && grid[newRow][newCol] &&
                    !visited[newRow][newCol]) {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
        return fishCount;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), result = 0;
        vector<vector<bool>> visited(numRows, vector<bool>(numCols));

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    result = max(result, countFishes(grid, visited, i, j));
                }
            }
        }
        return result;
    }
};