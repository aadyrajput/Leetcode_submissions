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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next; len++;
        }
        int tar=len-n+1;
        if(tar==1){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode* prev=NULL; ListNode* temp2=head; int ctx=0;
        while(temp2){
            ctx++;
        if(ctx==tar)break;
        prev=temp2;
        temp2=temp2->next;
        }
        prev->next=temp2->next;
        delete temp2;
        return head;

    }
};