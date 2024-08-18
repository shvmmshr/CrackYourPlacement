class Solution {
public:
    void listtostack(ListNode* l, stack<int>& s){
        while(l){
            s.push(l->val);
            l = l->next;
        }
    }
    
    void stacktolist(stack<int>& s, ListNode* l){
        while(!s.empty()){
            l->val = s.top();
            s.pop();
            if (!s.empty()) {
                l->next = new ListNode(0);
                l = l->next;
            }
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2, res;
        listtostack(l1, s1);
        listtostack(l2, s2);
        int carry = 0;
        while(!s1.empty() || !s2.empty()){
            int a = 0, b = 0;
            if(!s1.empty()){
                a = s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                b = s2.top();
                s2.pop();
            }
            int sum = a + b + carry;
            carry = sum / 10;
            res.push(sum % 10);
        }
        if(carry){
            res.push(carry);
        }
        ListNode* head = new ListNode(0);
        stacktolist(res, head);
        return head;
    }
};
