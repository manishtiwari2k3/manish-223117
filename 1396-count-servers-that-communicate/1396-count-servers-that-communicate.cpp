// // class Solution {
// // public:
// //     int countServers(vector<vector<int>>& grid) {
// //         int numRows = grid.size(), numCols = grid[0].size();
// //         int communicableServersCount = 0;

// //         for (int row = 0; row < numRows; ++row) {
// //             for (int col = 0; col < numCols; ++col) {
// //                 if (grid[row][col] == 1) {
// //                     bool canCommunicate = false;

// //                     for (int otherCol = 0; otherCol < numCols; ++otherCol) {
// //                         if (otherCol != col && grid[row][otherCol] == 1) {
// //                             canCommunicate = true;
// //                             break;
// //                         }
// //                     }

// //                     if (canCommunicate) {
// //                         communicableServersCount++;
// //                     } else {
// //                         for (int otherRow = 0; otherRow < numRows; ++otherRow) {
// //                             if (otherRow != row && grid[otherRow][col] == 1) {
// //                                 canCommunicate = true;
// //                                 break;
// //                             }
// //                         }

// //                         if (canCommunicate) {
// //                             communicableServersCount++;
// //                         }
// //                     }
// //                 }
// //             }
// //         }

// //         return communicableServersCount;
// //     }
// // };


// class Solution {
// public:
//     int countServers(const vector<vector<int>>& grid) {
//         vector<int> rowCounts(size(grid[0]), 0), colCounts(size(grid), 0);

//         for (int row = 0; row < size(grid); ++row)
//             for (int col = 0; col < size(grid[0]); ++col)
//                 if (grid[row][col]) {
//                     rowCounts[col]++;
//                     colCounts[row]++;
//                 }

//         int communicableServersCount = 0;

//         for (int row = 0; row < size(grid); ++row)
//             for (int col = 0; col < size(grid[0]); ++col)
//                 if (grid[row][col])
//                     communicableServersCount +=
//                         rowCounts[col] > 1 || colCounts[row] > 1;

//         return communicableServersCount;
//     }
// };

class Solution {
public:
    int countServers(const vector<vector<int>>& grid) {
        int communicableServersCount = 0;
        vector<int> rowCounts(size(grid[0]), 0),
            lastServerInCol(size(grid), -1);

        // First pass to count servers in each row and column
        for (int row = 0; row < size(grid); ++row) {
            int serverCountInRow = 0;
            for (int col = 0; col < size(grid[0]); ++col)
                if (grid[row][col]) {
                    serverCountInRow++;
                    rowCounts[col]++;
                    lastServerInCol[row] = col;
                }
            if (serverCountInRow != 1)
                communicableServersCount += serverCountInRow,
                    lastServerInCol[row] = -1;
        }

        for (int row = 0; row < size(grid); ++row)
            communicableServersCount += lastServerInCol[row] != -1 &&
                                        rowCounts[lastServerInCol[row]] > 1;

        return communicableServersCount;
    }
};