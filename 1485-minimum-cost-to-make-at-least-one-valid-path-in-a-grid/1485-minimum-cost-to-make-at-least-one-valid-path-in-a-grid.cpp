// class Solution {
// public:
//     int minCost(vector<vector<int>>& grid) {
//         int numRows = grid.size(), numCols = grid[0].size();
//         vector<vector<int>> minChanges(numRows, vector<int>(numCols, INT_MAX));

//         minChanges[0][0] = 0;

//         while (true) {
//             vector<vector<int>> prevState = minChanges;

//             for (int row = 0; row < numRows; row++) {
//                 for (int col = 0; col < numCols; col++) {
//                     if (row > 0) {
//                         minChanges[row][col] =
//                             min(minChanges[row][col],
//                                 minChanges[row - 1][col] +
//                                     (grid[row - 1][col] == 3 ? 0 : 1));
//                     }
//                     if (col > 0) {
//                         minChanges[row][col] =
//                             min(minChanges[row][col],
//                                 minChanges[row][col - 1] +
//                                     (grid[row][col - 1] == 1 ? 0 : 1));
//                     }
//                 }
//             }

//             for (int row = numRows - 1; row >= 0; row--) {
//                 for (int col = numCols - 1; col >= 0; col--) {
//                     if (row < numRows - 1) {
//                         minChanges[row][col] =
//                             min(minChanges[row][col],
//                                 minChanges[row + 1][col] +
//                                     (grid[row + 1][col] == 4 ? 0 : 1));
//                     }
//                     if (col < numCols - 1) {
//                         minChanges[row][col] =
//                             min(minChanges[row][col],
//                                 minChanges[row][col + 1] +
//                                     (grid[row][col + 1] == 2 ? 0 : 1));
//                     }
//                 }
//             }

//             if (prevState == minChanges) {
//                 break;
//             }
//         }

//         return minChanges[numRows - 1][numCols - 1];
//     }
// };

class Solution {
public:
    // Direction vectors: right, left, down, up (matching grid values 1, 2, 3,
    // 4)
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();

        // Min-heap ordered by cost. Each element is {cost, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));
        minCost[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0], row = curr[1], col = curr[2];

            // Skip if we've found a better path to this cell
            if (minCost[row][col] != cost) continue;

            // Try all four directions
            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];

                // Check if new position is valid
                if (newRow >= 0 && newRow < numRows && newCol >= 0 &&
                    newCol < numCols) {
                    // Add cost=1 if we need to change direction
                    int newCost = cost + (dir != (grid[row][col] - 1) ? 1 : 0);

                    // Update if we found a better path
                    if (minCost[newRow][newCol] > newCost) {
                        minCost[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }
};