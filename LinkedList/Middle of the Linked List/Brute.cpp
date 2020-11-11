// O(n) + O(n/2)
// Two Pass Algo
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
    ListNode* middleNode(ListNode* head)
    {
        ListNode* ptr = head;
        int size = 0;
        
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            size += 1;
        }
        
        ptr = head;
        for(int i=1;i<=size/2;i++)
        {
            ptr=ptr->next;
        }
        
        return ptr;
    }
};
