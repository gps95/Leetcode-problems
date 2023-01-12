/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* p) {
        if(!p) return nullptr;
        p->next=nullptr;
        conectar(p);
        return p;
    }
    
    void conectar(Node* p) {
        if(p->left){
            p->left->next=p->right;
            p->right->next = p->next?p->next->left:nullptr;
            conectar(p->left);
            conectar(p->right);
        }
    }
};