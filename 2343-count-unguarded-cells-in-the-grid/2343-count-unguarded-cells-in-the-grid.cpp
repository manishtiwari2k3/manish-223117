// class Solution {
// public:
//     const int UNGUARDED = 0;
//     const int GUARDED = 1;
//     const int GUARD = 2;
//     const int WALL = 3;

//     void markguarded(int row, int col, vector<vector<int>>& grid) {
//         for (int r = row - 1; r >= 0; r--) {
//             if (grid[r][col] == WALL || grid[r][col] == GUARD) break;
//             grid[r][col] = GUARDED;
//         }
//         for (int r = row + 1; r < grid.size(); r++) {
//             if (grid[r][col] == WALL || grid[r][col] == GUARD) break;
//             grid[r][col] = GUARDED;
//         }
//         for (int c = col - 1; c >= 0; c--) {
//             if (grid[row][c] == WALL || grid[row][c] == GUARD) break;
//             grid[row][c] = GUARDED;
//         }
//         for (int c = col + 1; c < grid[row].size(); c++) {
//             if (grid[row][c] == WALL || grid[row][c] == GUARD) break;
//             grid[row][c] = GUARDED;
//         }
//     }

//     int countUnguarded(int m, int n, vector<vector<int>>& guards,
//                        vector<vector<int>>& walls) {
//         vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

//         for (const auto& guard : guards) {
//             grid[guard[0]][guard[1]] = GUARD;
//         }

//         for (const auto& wall : walls) {
//             grid[wall[0]][wall[1]] = WALL;
//         }
//         for (const auto& guard : guards) {
//             markguarded(guard[0], guard[1], grid);
//         }

//         int count = 0;
//         for (const auto& row : grid) {
//             for (const auto& cell : row) {
//                 if (cell == UNGUARDED) count++;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void recurse(int row, int col, vector<vector<int>>& grid, char direction) {
        if (row < 0 || row >= grid.size() || col < 0 ||
            col >= grid[row].size() || grid[row][col] == GUARD ||
            grid[row][col] == WALL) {
            return;
        }
        grid[row][col] = GUARDED; 
        if (direction == 'U') recurse(row - 1, col, grid, 'U');  
        if (direction == 'D') recurse(row + 1, col, grid, 'D');  
        if (direction == 'L') recurse(row, col - 1, grid, 'L');  
        if (direction == 'R') recurse(row, col + 1, grid, 'R');  
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        for (const auto& guard : guards) {
            recurse(guard[0] - 1, guard[1], grid, 'U');  
            recurse(guard[0] + 1, guard[1], grid, 'D');  
            recurse(guard[0], guard[1] - 1, grid, 'L');  
            recurse(guard[0], guard[1] + 1, grid, 'R');  
        }

        int count = 0;
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell == UNGUARDED) count++;
            }
        }
        return count;
    }
};