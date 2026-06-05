/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*, int> mp1;
        unordered_map<ListNode*, int> mpp;

        while(headA && headB)
        {
            mpp[headB]++;
            mp1[headA]++;
            if(mp1.find(headB)!= mp1.end()) return headB;
            
            if(mpp.find(headA)!= mpp.end()) return headA;
   
            headA = headA->next;
            headB = headB->next;
        }

        while(headA)
        {
            if(mpp.find(headA) != mpp.end()) return headA;
            headA = headA->next;
        }

        while(headB)
        {
            if(mp1.find(headB) != mp1.end()) return headB;
            headB = headB->next;
        }

        return NULL;
    }
};