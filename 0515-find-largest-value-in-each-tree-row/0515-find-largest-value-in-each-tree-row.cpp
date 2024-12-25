// // class Solution {
// // public:
// //     vector<int> largestValues(TreeNode* root) {
// //         if (root == nullptr) {
// //             return vector<int>{};
// //         }
        
// //         vector<int> ans;
// //         queue<TreeNode*> queue;
// //         queue.push(root);
        
// //         while (!queue.empty()) {
// //             int currentLength = queue.size();
// //             int currMax = INT_MIN;
            
// //             for (int i = 0; i < currentLength; i++) {
// //                 TreeNode* node = queue.front();
// //                 queue.pop();
// //                 currMax = max(currMax, node->val);
                
// //                 if (node->left) {
// //                     queue.push(node->left);
// //                 }
                
// //                 if (node->right) {
// //                     queue.push(node->right);
// //                 }
// //             }
            
// //             ans.push_back(currMax);
// //         }
        
// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     vector<int> ans;
    
//     vector<int> largestValues(TreeNode* root) {
//         dfs(root, 0);
//         return ans;
//     }
    
//     void dfs(TreeNode* node, int depth) {
//         if (node == nullptr) {
//             return;
//         }
        
//         if (depth == ans.size()) {
//             ans.push_back(node->val);
//         } else {
//             ans[depth] = max(ans[depth], node->val);
//         }
        
//         dfs(node->left, depth + 1);
//         dfs(node->right, depth + 1);
//     }
// };

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }
        
        vector<int> ans;
        stack<pair<TreeNode*, int>> stack;
        stack.push(make_pair(root, 0));
        
        while (!stack.empty()) {
            pair<TreeNode*, int> pair = stack.top();
            stack.pop();
            TreeNode* node = pair.first;
            int depth = pair.second;
            
            if (depth == ans.size()) {
                ans.push_back(node->val);
            } else {
                ans[depth] = max(ans[depth], node->val);
            }
            
            if (node->left) {
                stack.push(make_pair(node->left, depth + 1));
            }
            
            if (node->right) {
                stack.push(make_pair(node->right, depth + 1));
            }
        }
        
        return ans;
    }
};