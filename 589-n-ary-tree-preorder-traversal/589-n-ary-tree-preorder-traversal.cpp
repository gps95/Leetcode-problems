/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    using vi = vector<int>;
    vi preorder(Node* root) {
        vi ret;
       pre(ret,root);
        return ret;
    }

    void pre(vi & v,Node* node){
        if(!node)return;
        v.push_back(node->val);
        for(auto n:node->children)
            pre(v,n);
    }
};


















