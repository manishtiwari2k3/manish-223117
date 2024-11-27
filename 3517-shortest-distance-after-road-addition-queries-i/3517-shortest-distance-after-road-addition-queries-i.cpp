// class Solution {
// public:
//     int bfs(int n, vector<vector<int>>& adjList) {
//         vector<bool> visited(n, false);
//         queue<int> nodeQueue;
//         nodeQueue.push(0);
//         visited[0] = true;

//         int currentLayerNodeCount = 1;
//         int nextLayerNodeCount = 0;
//         int layersExplored = 0;

//         while (!nodeQueue.empty()) {
//             for (int i = 0; i < currentLayerNodeCount; ++i) {
//                 int currentNode = nodeQueue.front();
//                 nodeQueue.pop();

//                 if (currentNode == n - 1) {
//                     return layersExplored;  
//                 }

//                 for (auto neighbor : adjList[currentNode]) {
//                     if (visited[neighbor]) continue;
//                     nodeQueue.push(
//                         neighbor);  
//                     nextLayerNodeCount++;  
//                     visited[neighbor] = true;
//                 }
//             }

//             currentLayerNodeCount = nextLayerNodeCount;
//             nextLayerNodeCount = 0;
//             layersExplored++;  
//         }

//         return -1;  
//     }

//     vector<int> shortestDistanceAfterQueries(int n,
//                                              vector<vector<int>>& queries) {
//         vector<int> answer;
//         vector<vector<int>> adjList(n, vector<int>(0));

//         for (int i = 0; i < n - 1; i++) {
//             adjList[i].push_back(i + 1);
//         }
//         for (auto& road : queries) {
//             int u = road[0];
//             int v = road[1];
//             adjList[u].push_back(v); 
//             answer.push_back(bfs(n, adjList));
//         }

//         return answer;
//     }
// };

class Solution {
public:
    int findMinDistance(vector<vector<int>> &adjList, int n, int currentNode,
                        vector<int> &dp) {
        if (currentNode == n - 1) return 0;

        if (dp[currentNode] != -1) return dp[currentNode];

        int minDistance = n;

        for (int neighbor : adjList[currentNode]) {
            minDistance =
                min(minDistance, findMinDistance(adjList, n, neighbor, dp) + 1);
        }

        return dp[currentNode] = minDistance;
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries) {
        vector<int> dp(
            n, -1); 
        vector<vector<int>> adjList(n, vector<int>(0));

        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }

        vector<int> answer;

        for (auto &road : queries) {
            int u = road[0];
            int v = road[1];

            adjList[u].push_back(v);
            answer.push_back(findMinDistance(adjList, n, 0, dp));

            dp.clear();
            dp.resize(n, -1);
        }

        return answer; 
    }
};