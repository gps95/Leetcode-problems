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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        sum=tree(root,false);
        return sum;
    }

    int tree(TreeNode* & node,bool isLeftChild){
        if(!node)return 0;
        int sum=0;
        if(!node->left && !node->right && isLeftChild) return node->val;
        sum+=tree(node->left,true);
        sum+=tree(node->right,false);
        return sum;
    }
};