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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        ListNode *A=list1,*B=list2,start=ListNode(),*Act = &start;
        
        while(A && B){//While both are not at the end
            if(A->val<=B->val){
                Act->next=A;
                Act=Act->next;
                A=A->next;
            }
            else{//A>B
                Act->next=B;
                Act=Act->next;
                B=B->next;
            }
        }
        //either A or B or both are at the end
        if(A) Act->next=A;
        if(B) Act->next=B;
        return start.next;
    }
};