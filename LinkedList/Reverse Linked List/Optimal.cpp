// O(n) TC and O(1) SC
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* d = NULL;
        
        while(head!=NULL)
        {
            temp = temp->next;
            head->next = d;
            d = head;
            head = temp;
        }
        return d;
    }
};
