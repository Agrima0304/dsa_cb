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
    ListNode* middle(ListNode* head)
    {
        
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return true;
        }
        if(head->next->next==NULL&&head->val==head->next->val)
        {
            return true;
        }
           if(head->next->next==NULL&&head->val!=head->next->val)
        {
            return false;
        }
     ListNode *mid=middle(head);
     //now reverse the linkedlist
     ListNode *prev=nullptr;
     ListNode *curr=mid;
     while(curr!=NULL)
     {
         ListNode *n=curr->next;
         curr->next=prev;
         prev=curr;
         curr=n;
     }
     ListNode *p=prev;
     ListNode *start=head;
     while(start!=mid)
     {
         if(start->val!=p->val)
         {
             return false;
         }
         start=start->next;
         p=p->next;
     }
     return true;   
    }
};
