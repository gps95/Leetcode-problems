/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val || root->val==q->val || (root->val>p->val && root->val<q->val)
           ||(root->val<p->val && root->val>q->val)) return root;
        //on same side
        if(root->val<p->val){
            if(root->right)
                return lowestCommonAncestor(root->right,p,q);
        }
        else{
            if(root->left)
                return lowestCommonAncestor(root->left,p,q);
        }
        return nullptr;
    }
};