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
    int gcd(int a,int b){
        int count=1;
        for(int i=1;i<=((a<b)?a:b);i++){
            if(a%i==0 && b%i==0) count=max(count,i);
        }
        return count;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        if(curr==NULL) return head;
        while(curr){
            ListNode* temp=new ListNode();
            temp->val=gcd(prev->val,curr->val);
            prev->next=temp;
            temp->next=curr;
            prev=prev->next->next;
            curr=curr->next;
        }
        return head;
    }
};