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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=l1;
        while(l2!=NULL){
            l1->val+=l2->val;
            if(l1->val>=10){
                l1->val-=10;
                if(l1->next==NULL) l1->next=new ListNode(1);
                else l1->next->val++;
            }
            if(l1->next==NULL && l2->next!=NULL) l1->next=new ListNode(0);
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            if(l1->val>=10){
                l1->val-=10;
                if(l1->next==NULL) l1->next=new ListNode(1);
                else l1->next->val++;
            }
            if(l1->next==NULL && l1->val>=10) l1->next=new ListNode(0);
            l1=l1->next;
        }
        return temp;
    }
};