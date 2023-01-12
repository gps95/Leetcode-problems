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
    int maxDepth(TreeNode* root) {
        int depth=0;
        tree(root,depth);
        return depth;
    }
    
    void tree(TreeNode * node,int &depth){
        if(!node)return;
        int di=depth+1,dd=depth+1;
        if(node->left) tree(node->left,di);
        if(node->right) tree(node->right,dd);
        depth=max(di,dd);
    }
};