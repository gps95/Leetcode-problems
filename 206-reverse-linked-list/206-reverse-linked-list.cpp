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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;//if head is empty,return it
        
        //next has next node,cur has current node and prev has previous node
        ListNode *prev=head,*next=head->next,*cur;
        prev->next=nullptr;
        
        while(next){//while next node!=nullptr
            cur=next;
            next=next->next;
            cur->next=prev;
            prev=cur;
        }
        return prev;
    }
};