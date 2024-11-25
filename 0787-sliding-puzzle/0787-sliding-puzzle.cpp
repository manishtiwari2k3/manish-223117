// // #include <vector>
// // #include <string>
// // #include <unordered_set>
// // #include <algorithm>

// // using namespace std;

// // class Solution {
// // public:
// //     int slidingPuzzle(vector<vector<int>>& board) {
// //         // Convert the board to a string for state representation
// //         string start = "";
// //         for (const auto& row : board) {
// //             for (int num : row) {
// //                 start += to_string(num);
// //             }
// //         }
// //         string target = "123450";
        
// //         // Define neighbors for the 2x3 grid (indices where '0' can move)
// //         vector<vector<int>> neighbors = {
// //             {1, 3},    // index 0
// //             {0, 2, 4}, // index 1
// //             {1, 5},    // index 2
// //             {0, 4},    // index 3
// //             {1, 3, 5}, // index 4
// //             {2, 4}     // index 5
// //         };
        
// //         unordered_set<string> visited; // To avoid revisiting states
// //         int result = dfs(start, target, neighbors, visited, 0);
// //         return result == INT_MAX ? -1 : result;
// //     }

// // private:
// //     int dfs(string& state, const string& target, const vector<vector<int>>& neighbors,
// //             unordered_set<string>& visited, int depth) {
// //         // If the state is the target, return the current depth
// //         if (state == target) {
// //             return depth;
// //         }
        
// //         // If the state has been visited, return a large value to signify no solution
// //         if (visited.count(state)) {
// //             return INT_MAX;
// //         }
        
// //         visited.insert(state);
// //         int zeroIndex = state.find('0');
// //         int minMoves = INT_MAX;
        
// //         // Explore all possible moves
// //         for (int neighbor : neighbors[zeroIndex]) {
// //             string newState = state;
// //             swap(newState[zeroIndex], newState[neighbor]);
// //             minMoves = min(minMoves, dfs(newState, target, neighbors, visited, depth + 1));
// //         }
        
// //         visited.erase(state); // Backtrack
// //         return minMoves;
// //     }
// // };

// class Solution {
// public:
//     vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
//                                       {0, 4}, {3, 5, 1}, {4, 2}};

// public:
//     int slidingPuzzle(vector<vector<int>>& board) {
//         string startState;
//         for (int i = 0; i < 2; i++) {
//             for (int j = 0; j < 3; j++) {
//                 startState += to_string(board[i][j]);
//             }
//         }
//         unordered_map<string, int> visited;
//         dfs(startState, visited, startState.find('0'), 0);

//         return visited.count("123450") ? visited["123450"] : -1;
//     }

// private:
//     void dfs(string state, unordered_map<string, int>& visited, int zeroPos,
//              int moves) {
//         if (visited.count(state) && visited[state] <= moves) {
//             return;
//         }
//         visited[state] = moves;

//         for (int nextPos : directions[zeroPos]) {
//             swap(state[zeroPos], state[nextPos]);  
//             dfs(state, visited, nextPos,
//                 moves + 1);
//             swap(state[zeroPos],
//                  state[nextPos]);  
//         }
//     }
// };

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                          {0, 4}, {1, 3, 5}, {2, 4}};

        string target = "123450";
        string startState;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                startState += to_string(board[i][j]);
            }
        }

        unordered_set<string> visited; 
        queue<string> queue;
        queue.push(startState);
        visited.insert(startState);

        int moves = 0;

        while (!queue.empty()) {
            int size = queue.size();
            while (size-- > 0) {
                string currentState = queue.front();
                queue.pop();

                if (currentState == target) {
                    return moves;
                }

                int zeroPos = currentState.find('0');
                for (int newPos : directions[zeroPos]) {
                    string nextState = currentState;
                    swap(nextState[zeroPos], nextState[newPos]);

                    if (visited.count(nextState)) continue;

                    visited.insert(nextState);
                    queue.push(nextState);
                }
            }
            moves++;
        }
        return -1;
    }
};

