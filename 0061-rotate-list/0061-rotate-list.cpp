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
    ListNode* rotateRight(ListNode* head, int k) {
     if(head==NULL || k==0)return head;
     ListNode* temp=head;
     int n=0;
     for(int i=0;i<k;i++){
        if(temp==NULL) break;
        n++; 
        temp=temp->next;
     }

     if(temp==NULL){
        k=k%n;
     }

    if(k==0)return head;

    temp=head;
    for(int i=0;i<k;i++){
        temp=temp->next;
    }
    ListNode* prev=head;
    while(temp->next!=NULL){
        temp=temp->next;
        prev=prev->next;
    }

    ListNode* newhead=prev->next;
    prev->next=NULL;

    temp->next=head;
     
    return newhead;
    }
};