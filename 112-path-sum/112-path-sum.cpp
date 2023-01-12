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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hassum(root,0,targetSum);
    }
    
    bool hassum(TreeNode* node,int sum,const int &targetSum){
        if(!node) return false;
        if(!node->left && !node->right && sum+node->val==targetSum)return true;
        sum+=node->val;
        return hassum(node->left,sum,targetSum) || hassum(node->right,sum,targetSum);
    }
};