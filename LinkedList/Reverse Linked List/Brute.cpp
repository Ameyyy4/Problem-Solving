// O(n) TC and O(n) SC
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
        
        if(head == NULL)
            return head;
        vector<ListNode*> vec;
        
        while(head!=NULL)
        {
            vec.push_back(head);
            head = head->next;
        }
        
        int size = (int) vec.size();
        if(size == 1)
            return vec[0];
        
        ListNode* temp = vec[size-1];
        int i=size-2;
        
        while(i>=0)
        {
            temp->next = vec[i];
            temp = temp->next;
            i--;
        }
        temp->next = NULL;
        
        return vec[size-1];
    }
};
