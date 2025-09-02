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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)return NULL;
        int ctx=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next; ctx++;
        }
    int tar=ctx/2;  tar++;
    int ct=0;
    ListNode* curr=head; ListNode* prev=NULL;
    while(curr){
        ct++;
        if(ct==tar) break;
        prev=curr; curr=curr->next;
    }
    if(curr->next==NULL){
        prev->next=NULL;
        delete curr;
        return head; 
    }
    prev->next=curr->next;
    curr->next=NULL; delete curr;
    return head;



    }
};