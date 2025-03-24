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
    int maxp(TreeNode* root,int& maxpath){
        if(root==NULL){
            return 0;
        }
        int lh = max(0,maxp(root->left,maxpath));
        int rh = max(0,maxp(root->right,maxpath));
        maxpath = max(maxpath,lh+rh+root->val);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxpath = INT_MIN;
        maxp(root,maxpath);
        return maxpath;
    }
};