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
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr;
        return checktree(root,prev);
    }
    
    bool checktree(TreeNode *node,TreeNode *&prev){
        if(!node) return true;
        if(!checktree(node->left,prev))return false;
        if(prev && prev->val>=node->val) return false;
        prev=node;
        return checktree(node->right,prev);
    }
};