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
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));
        minCost[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0], row = curr[1], col = curr[2];

            if (minCost[row][col] != cost) continue;

            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];

                if (newRow >= 0 && newRow < numRows && newCol >= 0 &&
                    newCol < numCols) {
                    int newCost = cost + (dir != (grid[row][col] - 1) ? 1 : 0);

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