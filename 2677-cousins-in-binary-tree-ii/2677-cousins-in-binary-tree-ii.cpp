/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* replaceValueInTree(TreeNode* root) {
//         if (!root) return root;

//         queue<TreeNode*> nodeQueue;
//         nodeQueue.push(root);
//         vector<int> levelSums;
//         while (!nodeQueue.empty()) {
//             int levelSum = 0;
//             int levelSize = nodeQueue.size();
//             for (int i = 0; i < levelSize; ++i) {
//                 TreeNode* currentNode = nodeQueue.front();
//                 nodeQueue.pop();
//                 levelSum += currentNode->val;
//                 if (currentNode->left) nodeQueue.push(currentNode->left);
//                 if (currentNode->right) nodeQueue.push(currentNode->right);
//             }
//             levelSums.push_back(levelSum);
//         }

//         nodeQueue.push(root);
//         int levelIndex = 1;
//         root->val = 0;  
//         while (!nodeQueue.empty()) {
//             int levelSize = nodeQueue.size();
//             for (int i = 0; i < levelSize; ++i) {
//                 TreeNode* currentNode = nodeQueue.front();
//                 nodeQueue.pop();

//                 int siblingSum =
//                     (currentNode->left ? currentNode->left->val : 0) +
//                     (currentNode->right ? currentNode->right->val : 0);

//                 if (currentNode->left) {
//                     currentNode->left->val = levelSums[levelIndex] - siblingSum;
//                     nodeQueue.push(currentNode->left);
//                 }
//                 if (currentNode->right) {
//                     currentNode->right->val =
//                         levelSums[levelIndex] - siblingSum;
//                     nodeQueue.push(currentNode->right);
//                 }
//             }
//             ++levelIndex;
//         }

//         return root;
//     }
// };








class Solution {
private:
    int levelSums[100000];

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        calculateLevelSum(root, 0);            
        replaceValueInTreeInternal(root, 0, 0);  
        return root;
    }
    void calculateLevelSum(TreeNode* node, int level) {
        if (node == nullptr) {
            return;
        }

        levelSums[level] += node->val; 
        calculateLevelSum(node->left, level + 1); 
        calculateLevelSum(node->right, level + 1);  
    }

    void replaceValueInTreeInternal(TreeNode* node, int siblingSum, int level) {
        if (node == nullptr) {
            return;
        }

        int leftChildVal = node->left == nullptr ? 0 : node->left->val;
        int rightChildVal = node->right == nullptr ? 0 : node->right->val;

        if (level == 0 || level == 1) {
            node->val = 0;
        } else {
            node->val = levelSums[level] - node->val - siblingSum;
        }
        replaceValueInTreeInternal(node->left, rightChildVal, level + 1);
        replaceValueInTreeInternal(node->right, leftChildVal, level + 1);
    }
};