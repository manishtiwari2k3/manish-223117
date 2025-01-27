// class Solution {
// public:
//     bool isPrerequisite(unordered_map<int, vector<int>>& adjList,
//                         vector<bool>& visited, int src, int target) {
//         visited[src] = 1;

//         if (src == target) {
//             return true;
//         }

//         int answer = false;
//         for (auto adj : adjList[src]) {
//             if (!visited[adj]) {
//                 answer =
//                     answer || isPrerequisite(adjList, visited, adj, target);
//             }
//         }
//         return answer;
//     }

//     vector<bool> checkIfPrerequisite(int numCourses,
//                                      vector<vector<int>>& prerequisites,
//                                      vector<vector<int>>& queries) {
//         unordered_map<int, vector<int>> adjList;
//         for (auto edge : prerequisites) {
//             adjList[edge[0]].push_back(edge[1]);
//         }

//         vector<bool> answer;
//         for (auto q : queries) {
//             vector<bool> visited(numCourses, false);
//             answer.push_back(isPrerequisite(adjList, visited, q[0], q[1]));
//         }

//         return answer;
//     }
// };

class Solution {
public:
    void preprocess(int numCourses, vector<vector<int>>& prerequisites,
                    unordered_map<int, vector<int>>& adjList,
                    vector<vector<bool>>& isPrerequisite) {
        for (int i = 0; i < numCourses; i++) {
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto adj : adjList[node]) {
                    if (!isPrerequisite[i][adj]) {
                        isPrerequisite[i][adj] = true;
                        q.push(adj);
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<vector<bool>> isPrerequisite(numCourses,
                                            vector<bool>(numCourses, false));
        preprocess(numCourses, prerequisites, adjList, isPrerequisite);

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(isPrerequisite[q[0]][q[1]]);
        }

        return answer;
    }
};