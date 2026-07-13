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
    ListNode* findMiddle(ListNode* z){
        ListNode* slow=z;
        ListNode* fast=z->next;         // slight change->do fast=head->next,so we get 1st middle incase of even
         while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
    return slow;
    }

     ListNode* merge(ListNode *x,ListNode* y){
        ListNode* temp1=x;
        ListNode* temp2=y;

        ListNode* dummy= new ListNode(-1);
        ListNode* t=dummy;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                t->next=temp1;
                temp1=temp1->next;
                t=t->next;
            }    
            else{
                t->next=temp2;
                temp2=temp2->next;
                t=t->next;
            }
        }
        
        if(temp1){t->next=temp1;}
        if(temp2){t->next=temp2;}

    return dummy->next;
    }


    ListNode* sortList(ListNode* head) {

        if(head==NULL || head->next==NULL)return head;

        ListNode* middle=findMiddle(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;

        left=sortList(left);
        right=sortList(right);
        return merge(left,right);

    }
};