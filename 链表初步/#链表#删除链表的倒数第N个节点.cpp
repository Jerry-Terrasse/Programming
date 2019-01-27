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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int i=0;
      ListNode* p;
      ListNode* h;
      ListNode* hr;
      bool bo=false;
      hr=p=h=head;
      for(i=0;i<n;i++)
      {
        if(p->next==NULL)
        {
          bo=true;
          break;
        }
        else
        {
          p=p->next;
        }
      }
      if(bo)
      {
        return hr->next;
      }
      for(;p->next!=NULL;)
      {
        h=h->next;
        p=p->next;
      }
      h->next=h->next->next;
      return hr;
    }
};
