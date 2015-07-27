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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * AnsNode;
        ListNode * pa;
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        int tmp;
        int carry =0;
        pa =new ListNode((p1->val+p2->val)%10);
        AnsNode = pa;
        carry = (p1->val + p2->val )/10;
        p1= p1->next;
        p2 = p2->next;
        while(p1 && p2){
             pa->next = new ListNode((p1->val+p2->val+carry)%10);
             carry = (p1->val + p2->val+carry)/10;
             pa = pa->next;
             p1= p1->next;
             p2 = p2->next;
        }
        if(p1){
          while(p1){
              pa->next = new ListNode((p1->val + carry)%10);
              carry  = (carry+p1->val)/10;
              p1 = p1->next;
              pa = pa->next;
          }
        }
        else if(p2){
            while(p2){
              pa->next = new ListNode((p2->val + carry)%10);
              carry  = (carry+p2->val)/10;
              p2 = p2->next;
              pa = pa->next;
          }
        }
          if(carry > 0)
              pa->next = new ListNode(carry);
          
        return AnsNode;

    }
};