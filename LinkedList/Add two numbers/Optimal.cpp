// O(n) TC and O(1) SC solution

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* temp1;
        ListNode* temp2;
        temp1 = l1;
        temp2 = l2;
        int size1 = 0;
        int size2 = 0;
        
        while(temp1)
        {
            temp1 = temp1->next;
            size1++;
            //cout<<size1<<endl;
        }
        while(temp2)
        {
            temp2 = temp2->next;
            size2++;
        }
        //cout<<size1<<" "<<size2<<endl;
        temp1 = l1;
        temp2 = l2;
        if(size1>size2)
        {
            while(temp1 && temp2)
            {
                temp1->val += temp2->val;
                if(temp1->val >= 10)
                {
                    temp1->val -= 10;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    temp1->val++;
                }
                else
                {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
            }
            while(temp1)
            {
                if(temp1->val >= 10)
                {
                    if(!temp1->next)
                    {
                        if(temp1->val >= 10)
                        {
                            ListNode* dummy = new ListNode;
                            temp1->val -= 10;
                            dummy->val = 1;
                            temp1->next = dummy;
                            return l1;
                        }
                        else
                            return l1;
                    }
                    temp1->val -= 10;
                    temp1 = temp1->next;
                    temp1->val++;
                }
                else
                    return l1;
            }
        }
        else
        {
            while(temp1 && temp2)
            {
                temp2->val += temp1->val;
                if(temp2->val >= 10)
                {
                    if(!temp2->next)
                    {
                        if(temp2->val >= 10)
                        {
                            ListNode* dummy = new ListNode;
                            temp2->val -= 10;
                            dummy->val = 1;
                            temp2->next = dummy;
                            return l2;
                        }
                        else
                            return l2;
                    }
                    temp2->val -= 10;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    temp2->val++;
                }
                else
                {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
            }
            while(temp2)
            {
                if(temp2->val >= 10)
                {
                    if(!temp2->next)
                    {
                        if(temp2->val >= 10)
                        {
                            ListNode* dummy = new ListNode;
                            temp2->val -= 10;
                            dummy->val = 1;
                            temp2->next = dummy;
                            return l2;
                        }
                        else
                            return l2;
                    }
                    temp2->val -= 10;
                    temp2 = temp2->next;
                    temp2->val++;
                }
                else
                    return l2;
            }
            return l2;
        }
        return l1;
    }
};
// Using carry variable
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* sum = new ListNode;
        ListNode* temp1;
        ListNode* temp2;
        temp1 = l1;
        temp2 = l2;
        int size1 = 0;
        int size2 = 0;
        
        while(temp1)
        {
            temp1 = temp1->next;
            size1++;
            //cout<<size1<<endl;
        }
        while(temp2)
        {
            temp2 = temp2->next;
            size2++;
        }
        //cout<<size1<<" "<<size2<<endl;
        
        if(size1 >= size2)
        {
            int carry = 0;
            sum->next = l1;
            temp1 = sum;
            while(l1)
            {
                if(l1 && l2)
                {
                    temp1 = temp1->next;
                    temp1->val = l1->val + l2->val + carry;
                }
                else if(l1)
                {
                    temp1 = temp1->next;
                    temp1->val = l1->val + carry;
                }
                carry = 0;
                if(temp1->val >= 10)
                {
                    temp1->val -= 10;
                    carry = 1;
                }
                l1 = l1->next;
                if(l2)
                    l2 = l2->next;
            }
            if(carry)
            {
                ListNode* dummy = new ListNode;
                dummy->val = carry;
                temp1->next = dummy;
            }
            return sum->next;
        }
        else
        {
            int carry = 0;
            sum->next = l2;
            temp1 = sum;
            while(l2)
            {
                if(l1 && l2)
                {
                    temp1 = temp1->next;
                    temp1->val = l1->val + l2->val + carry;
                }
                else if(l2)
                {
                    temp1 = temp1->next;
                    temp1->val = l2->val + carry;
                }
                carry = 0;
                if(temp1->val >= 10)
                {
                    temp1->val -= 10;
                    carry = 1;
                }
                l2 = l2->next;
                if(l1)
                    l1 = l1->next;
            }
            if(carry)
            {
                ListNode* dummy = new ListNode;
                dummy->val = carry;
                temp1->next = dummy;
            }
            return sum->next;
        }
    }
};
