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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<lists.size(); i++)
        {
            ListNode* a = lists[i];

            while(a!=NULL)
            {
                pq.push(a->val);
                a = a->next;
            }
        }

        if(pq.empty()) return NULL;
        ListNode* b = new ListNode(pq.top());
        pq.pop();
        ListNode* head =b;
        while(!pq.empty())
        {
            ListNode* c = new ListNode(pq.top());

            b->next = c;
            b = c;
            pq.pop();
        }

        return head;
    }
};