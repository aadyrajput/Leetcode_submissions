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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return false;
        ListNode* temp=head;
        while(temp){
            if(temp->val==1e6)return true;
            temp->val=1e6;
            temp=temp->next;
        }
    return false;
    }
};