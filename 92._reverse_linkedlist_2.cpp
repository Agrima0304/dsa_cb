class Solution {
public:
    ListNode* reverse(ListNode* head,int l,int r)
    {
         if(head==NULL||head->next==NULL)
         {
           return head;
         }
         ListNode* c=head;
          ListNode* prev=NULL;
          int i=1;
          while(i<=(r-l+1)&&c!=NULL)
          {
              ListNode *p=c->next;
              c->next=prev;
              prev=c;
              c=p;
              l++;
          }
          return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right) {
            return head;
        }
     
        ListNode* p=head;
        ListNode* q=head;
         ListNode* src1=NULL;
        int i=0;
        while(i<(left-1))
        {
          src1=p;
          p=p->next;
          i++;
        }
        int j=0;
        while(j<(right-1))
        {
          q=q->next;
          j++;
        }
        ListNode *src2=q->next;
        ListNode *h=reverse(p,left,right);
        if(src1==NULL)
        {
          head=h;
        }
        else
        {
        src1->next=h;
        }
        while(h->next!=NULL)
        {
         h=h->next;
        }
      h->next=src2;
      return head;
    }
};
