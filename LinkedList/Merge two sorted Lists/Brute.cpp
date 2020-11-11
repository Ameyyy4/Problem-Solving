// O(n+m) TC where n = size of l1 and m = size of l2
// O(n+m) SC
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* merged = new ListNode;
        ListNode* temp = merged;

        while(l1 && l2)
        {
            if((l1->val)<=(l2->val))
            {
                ListNode* dummy = new ListNode;
                dummy->val = l1->val;
                temp->next = dummy;
                temp = temp->next;
                l1 = l1->next;
            }
            else
            {
                ListNode* dummy = new ListNode;
                dummy->val = l2->val;
                temp->next = dummy;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        while(l1)
        {
                ListNode* dummy = new ListNode;
                dummy->val = l1->val;
                temp->next = dummy;
                temp = temp->next;
                l1 = l1->next;
        }
        while(l2)
        {
                ListNode* dummy = new ListNode;
                dummy->val = l2->val;
                temp->next = dummy;
                temp = temp->next;
                l2 = l2->next;
        }
        return merged->next;
        
    }
};
