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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode*>dq;
    dq.push(root);
    bool l2r = true;
    while(!dq.empty()){
        int n = dq.size();
        vector<int>level(n);
        for(int i=0;i<n;i++){
            TreeNode* node = dq.front();
            dq.pop();
            int index = (l2r) ? i : (n-1-i);
            level[index] = node->val;
            if(node->left){
                dq.push(node->left);
            }
            if(node->right){
                dq.push(node->right);
            }
            
        }
        ans.push_back(level);
        
    }
    return ans;
    }
};