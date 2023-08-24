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
            if(head==NULL||head->next==NULL)
            {
                return head;
            }
            ListNode *start=head->next;;
            ListNode *fast=head;
            while(start!=NULL&&start->next!=NULL)
            {
                start=start->next->next;
                fast=fast->next;
            }
          return fast;
        }
        ListNode* merge(ListNode* a1,ListNode* a2)
        {
            if(a1==NULL)
            {
                return a2;
            }
            if(a2==NULL)
            {
                return a1;
            }
            ListNode *c;
            if(a1->val<a2->val)
            {
                c=a1;
                c->next=merge(a1->next,a2);
            }
            else
            {
               c=a2;
             c->next=merge(a1,a2->next); 
            }
           return c;
        }
    ListNode* mergesort(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode *mid=middle(head);
        ListNode *a=head;
         ListNode *b=mid->next;
        
        mid->next=NULL;
        a=mergesort(a);
        b=mergesort(b);
        ListNode *p=merge(a,b);
        return p;
    }
    ListNode* sortList(ListNode* head) {
        ListNode *h=mergesort(head);
        return h;
        
    }
};
