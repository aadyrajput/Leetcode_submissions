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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int car=0;

        ListNode* ans=new ListNode(-1);
        ListNode* dum=ans;

        while(temp1!=NULL || temp2!=NULL){
            int z=0;
            if(temp1){z+=temp1->val; temp1=temp1->next;}
            if(temp2){z+=temp2->val; temp2=temp2->next;}
            z+=car;
            ListNode* x=new ListNode(z%10);
            car=(z/10);
             dum->next=x;
             dum=dum->next;
        }
        if(car==1){
            ListNode* x=new ListNode(car);
            dum->next=x;
        }
    
    return ans->next; 
    }
};