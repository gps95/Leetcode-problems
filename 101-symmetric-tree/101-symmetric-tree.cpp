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
    bool isSymmetric(TreeNode* root) {
        if(!root || (!root->left && root->right) || (root->left && !root->right)) return false;
        return isSym(root->left,root->right);
    }
    
    bool isSym(TreeNode* l,TreeNode * r){
        if(!l && !r) return true;
        if((!l && r) || (l && !r) || l->val != r->val) return false;
        bool b=false;
        b=isSym(l->left,r->right);
        if(b)b=isSym(l->right,r->left);
        else return false;
        return b;
    }
};