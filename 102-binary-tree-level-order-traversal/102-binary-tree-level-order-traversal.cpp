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
        if(!root)return {};
        vector<vector<int>> res={{}};
        int i=0,nextlevel=0,curlevel=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();q.pop();
            res[i].push_back(node->val);
            if(node->left){
                nextlevel++;
                q.push(node->left);
            }
            if(node->right){
                nextlevel++;
                q.push(node->right);
            }
            if(--curlevel==0){
                curlevel=nextlevel;
                nextlevel=0;
                if(!q.empty())res.push_back({});
                ++i;
            }
        }
        return res;
    }
};