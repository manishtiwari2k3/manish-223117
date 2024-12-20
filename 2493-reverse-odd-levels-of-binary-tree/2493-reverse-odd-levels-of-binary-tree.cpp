// class Solution {
// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         traverseDFS(root->left, root->right, 0);
//         return root;
//     }

// public:
//     void traverseDFS(TreeNode* leftChild, TreeNode* rightChild, int level) {
//         if (leftChild == nullptr || rightChild == nullptr) {
//             return;
//         }
//         if (level % 2 == 0) {
//             int temp = leftChild->val;
//             leftChild->val = rightChild->val;
//             rightChild->val = temp;
//         }

//         traverseDFS(leftChild->left, rightChild->right, level + 1);
//         traverseDFS(leftChild->right, rightChild->left, level + 1);
//     }
// };

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return nullptr;  // Return null if the tree is empty.
        }

        queue<TreeNode*> q;
        q.push(root);  // Start BFS with the root node.
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> currentLevelNodes;

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelNodes.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse node values if the current level is odd.
            if (level % 2 == 1) {
                int left = 0, right = currentLevelNodes.size() - 1;
                while (left < right) {
                    int temp = currentLevelNodes[left]->val;
                    currentLevelNodes[left]->val =
                        currentLevelNodes[right]->val;
                    currentLevelNodes[right]->val = temp;
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root;  // Return the modified tree root.
    }
};