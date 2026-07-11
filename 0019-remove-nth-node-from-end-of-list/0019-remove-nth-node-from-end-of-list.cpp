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
        int ct=0;
        ListNode* temp=head;
        while(temp){
            ct++; temp=temp->next;
        }
        int tar=ct-n+1;

        if(tar==1){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }

        int ctt=0;
        temp=head;

        while(temp){
            ctt++;
            if(ctt==tar-1) break;
            temp=temp->next;
        }

        ListNode* z=temp->next;
        temp->next=z->next;
        z->next=NULL;
        delete z;

    return head;
    }
};