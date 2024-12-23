// class Solution {
// public:
//     int minimumOperations(TreeNode* root) {
//         queue<TreeNode*> queue;
//         queue.push(root);
//         int totalSwaps = 0;
//         while (!queue.empty()) {
//             int levelSize = queue.size();
//             vector<int> levelValues(levelSize);

//             for (int i = 0; i < levelSize; i++) {
//                 TreeNode* node = queue.front();
//                 queue.pop();
//                 levelValues[i] = node->val;

//                 if (node->left != nullptr) queue.push(node->left);
//                 if (node->right != nullptr) queue.push(node->right);
//             }

//             totalSwaps += getMinSwaps(levelValues);
//         }
//         return totalSwaps;
//     }

// public:
//     int getMinSwaps(vector<int>& original) {
//         int swaps = 0;
//         vector<int> target = original;
//         sort(target.begin(), target.end());

//         unordered_map<int, int> pos;
//         for (int i = 0; i < original.size(); i++) {
//             pos[original[i]] = i;
//         }

//         for (int i = 0; i < original.size(); i++) {
//             if (original[i] != target[i]) {
//                 swaps++;

//                 int curPos = pos[target[i]];
//                 pos[original[i]] = curPos;
//                 swap(original[curPos], original[i]);
//             }
//         }
//         return swaps;
//     }
// };

class Solution {
    const int SHIFT = 20;
    const int MASK = 0xFFFFF;

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int swaps = 0;

        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<long long> nodes(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                nodes[i] = (static_cast<long long>(node->val) << SHIFT) + i;

                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }

            sort(nodes.begin(), nodes.end());
            for (int i = 0; i < levelSize; i++) {
                int origPos = static_cast<int>(nodes[i] & MASK);
                if (origPos != i) {
                    swap(nodes[i], nodes[origPos]);
                    swaps++;
                    i--;
                }
            }
        }
        return swaps;
    }
};