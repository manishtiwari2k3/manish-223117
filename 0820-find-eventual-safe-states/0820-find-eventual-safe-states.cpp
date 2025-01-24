// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> indegree(n);
//         vector<vector<int>> adj(n);

//         for (int i = 0; i < n; i++) {
//             for (auto node : graph[i]) {
//                 adj[node].push_back(i);
//                 indegree[i]++;
//             }
//         }

//         queue<int> q;
//         for (int i = 0; i < n; i++) {
//             if (indegree[i] == 0) {
//                 q.push(i);
//             }
//         }

//         vector<bool> safe(n);
//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();
//             safe[node] = true;

//             for (auto& neighbor : adj[node]) {
//                 indegree[neighbor]--;
//                 if (indegree[neighbor] == 0) {
//                     q.push(neighbor);
//                 }
//             }
//         }

//         vector<int> safeNodes;
//         for (int i = 0; i < n; i++) {
//             if (safe[i]) {
//                 safeNodes.push_back(i);
//             }
//         }
//         return safeNodes;
//     }
// };


class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visit,
             vector<bool>& inStack) {
        if (inStack[node]) {
            return true;
        }
        if (visit[node]) {
            return false;
        }
        visit[node] = true;
        inStack[node] = true;
        for (auto neighbor : adj[node]) {
            if (dfs(neighbor, adj, visit, inStack)) {
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visit(n), inStack(n);

        for (int i = 0; i < n; i++) {
            dfs(i, graph, visit, inStack);
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (!inStack[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};