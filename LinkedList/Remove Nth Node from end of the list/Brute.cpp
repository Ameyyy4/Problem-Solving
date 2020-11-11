// O(2*n) TC
// Double Pass Algo
// First we calculate the size and then remove the node
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int size = 0;
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            temp = temp->next;
            size++;
        }
        
        if(size == 1)
            return NULL;
        else
        {
            if(size == n)
                return head->next;
            else
            {
                int index = 2;
                temp = head;
                while(index != size-n+1)
                {
                    temp = temp->next;
                    index++;
                }
                temp->next = (temp->next)->next;
            }
        }
        return head;
    }
};
