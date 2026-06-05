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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        vector<int> v;

        ListNode* a = head;

        while(a)
        {
            v.push_back(a->val);
            a = a->next;
        }

        int num = v.size()/k;

        int j =0;

        for(int i=0; i<num; i++)
        {
            reverse(v.begin() +j, v.begin()+j+k);

            j+=k;
        }

        a = head;
        int i=0;
        while(a)
        {
            a->val = v[i];
            i++;
            a = a->next;
        }

        return head;
    }
};