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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        
        int n = len / k;
        int rem = len % k;

        curr = head;
        for (int i = 0; i < k; i++) {
            res[i] = curr;
            int part_size = n + (rem > 0 ? 1 : 0);
            for (int j = 0; j < part_size - 1; j++) {
                if (curr) curr = curr->next;
            }
            if (curr) { 
                ListNode* temp = curr->next;
                curr->next = nullptr;
                curr = temp;
            }
            if (rem > 0) rem--;
        }
        
        return res;
    }
};
