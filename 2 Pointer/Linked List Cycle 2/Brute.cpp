// O(n*n) TC and O(1) SC
// Great Soln
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* Curr,*temp;
        temp = Curr = head;
        
        while(Curr)
        {
            temp = head;
            while(temp)
            {
                if(Curr->next == temp)
                    return temp;
                else if(Curr == temp)
                    break;
                temp = temp->next;
            }
            Curr = Curr->next;
        }
        return NULL;
    }
};
