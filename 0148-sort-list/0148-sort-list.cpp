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
    ListNode* sortList(ListNode* head) {
        
        vector<int> arr;

        ListNode* a = head;

        while(a)
        {
            arr.push_back(a->val);
            a = a->next;
        }

        sort(arr.begin(), arr.end());

        a = head;
        int i=0;
        while(a)
        {
            a->val = arr[i];
            a = a->next;
            i++;
        }

        return head;
    }
};