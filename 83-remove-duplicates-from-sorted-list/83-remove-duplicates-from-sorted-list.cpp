/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *n = head,*prev=head;
        unordered_set<int> set;
        while(n){
            if(set.find(n->val)!=set.end())prev->next=n->next;
            else {
                set.insert(n->val);
                prev=n;
            }
            n=n->next;
        }
        return head;
    }
};