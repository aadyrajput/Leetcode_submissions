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
       if(head->next==NULL)return NULL;
        int ct=0;
        ListNode* temp=head;
        while(temp){
            ct++; temp=temp->next;
        } 
        int ans=ct/2; ans++; ct=0;
        temp=head; ListNode* prev=NULL; 
        while(temp){
            ct++;
            if(ct==ans-1) break;
            prev=temp;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};