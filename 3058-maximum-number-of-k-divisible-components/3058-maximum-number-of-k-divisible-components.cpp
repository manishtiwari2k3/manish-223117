// class Solution {
// public:
//     int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
//                                 vector<int> &values, int k) {
//         vector<int> adjList[n];
//         for (auto edge : edges) {
//             int node1 = edge[0];
//             int node2 = edge[1];
//             adjList[node1].push_back(node2);
//             adjList[node2].push_back(node1);
//         }
//         int componentCount = 0;
//         dfs(0, -1, adjList, values, k, componentCount);

//         return componentCount;
//     }

// private:
//     int dfs(int currentNode, int parentNode, vector<int> adjList[],
//             vector<int> &nodeValues, int k, int &componentCount) {
//         int sum = 0;

//         for (auto neighborNode : adjList[currentNode]) {
//             if (neighborNode != parentNode) {
//                 sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
//                            componentCount);
//                 sum %= k; 
//             }
//         }

//         sum += nodeValues[currentNode];

//         sum %= k;
//         if (sum == 0) componentCount++;

//         return sum;
//     }
// };


class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        // Base case: if there are less than 2 nodes, return 1
        if (n < 2) return 1;

        int componentCount = 0;
        unordered_map<int, unordered_set<int>> graph;

        // Step 1: Build the graph
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].insert(node2);
            graph[node2].insert(node1);
        }

        // Convert values to long long to prevent overflow
        vector<long long> longValues(values.begin(), values.end());

        // Step 2: Initialize the BFS queue with leaf nodes (nodes with only one
        // connection)
        queue<int> queue;
        for (const auto& [node, neighbors] : graph) {
            if (neighbors.size() == 1) {
                queue.push(node);
            }
        }

        // Step 3: Process nodes in BFS order
        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            // Find the neighbor node
            int neighborNode = -1;
            if (!graph[currentNode].empty()) {
                neighborNode = *graph[currentNode].begin();
            }

            if (neighborNode >= 0) {
                // Remove the edge between current and neighbor
                graph[neighborNode].erase(currentNode);
                graph[currentNode].erase(neighborNode);
            }

            // Check divisibility of the current node's value
            if (longValues[currentNode] % k == 0) {
                componentCount++;
            } else if (neighborNode >= 0) {
                // Add current node's value to the neighbor
                longValues[neighborNode] += longValues[currentNode];
            }

            // If the neighbor becomes a leaf node, add it to the queue
            if (neighborNode >= 0 && graph[neighborNode].size() == 1) {
                queue.push(neighborNode);
            }
        }

        return componentCount;
    }
};