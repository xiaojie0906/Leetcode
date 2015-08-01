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
    Solution():len(0){}
    
    bool isPalindrome(ListNode* head) {
        ListNode * tmp = head;
        while(tmp){
            tmp = tmp->next;
            len ++;
        }
        if(len < 2)
            return true;
		ListNode ** comptwo = &tmp;
        return isPalindrome(head,0,comptwo);
    }
	/*使用递归方式，cur表示当前节点的位置标号，compone指向当前节点，
	comptwo指向以链表中心为对称的与compone对应的节点
	*/
    bool isPalindrome(ListNode * compone,int cur,ListNode ** comptwo){
        bool ret = false;
        ListNode * my = compone;//保存当前要比较的节点
        if(cur < len/2 -1){//还在前半段
            ret = isPalindrome(compone->next,cur+1,comptwo);//使用递归，comptwo指向后半段与自己对应的点
            if(ret){
                ListNode * tmp = *comptwo;
                *comptwo = (*comptwo) ->next;//后半段的节点后移一位
               return   my->val == tmp->val;
            }
            return false;
        }
        else{//达到中点之后
			//comptwo 指向中心之后第一个要判断的节点
            if(len%2)
                *comptwo = compone->next->next;
            else
                *comptwo = compone->next;
            ListNode * tmp = *comptwo;
            *comptwo = (*comptwo) ->next;
             return  my->val == tmp->val;
        }
    }
private:
    int len;
};