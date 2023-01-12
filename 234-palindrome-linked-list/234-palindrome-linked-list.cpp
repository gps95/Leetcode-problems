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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        //slow at middle. Reverse from middle to end
        ListNode * prev=slow,*next;
        slow=slow->next;
        prev->next=nullptr;
        while(slow){
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        slow=prev;
        //second half of list reversed now compare slow and head
        while(slow){
            if(head->val!=slow->val)return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};














