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
        
        if(!head) return head;
        ListNode* a = head;
        ListNode* b = head->next;

        int curr = a->val;
        while(b)
        {
            int num = b->val;
            if(curr == num) b = b->next; 

            else 
            {
                a = a->next;
                a->val = num;
                curr = a->val;
                b=b->next;
            }
        } 

        a->next = NULL;

        return head;
    }
};