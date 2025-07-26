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
    ListNode* middleNode(ListNode* head) {
        int ct=0;
        ListNode* temp=head;
        while(temp!=NULL){
            ct++; temp=temp->next;
        }
        int ans=(ct+1)/2;
        if(ct%2==0) ans++; ct=0;
        while(head!=NULL){
            ct++;
            if(ct==ans)break;
            head=head->next;
        }
        return head;
    }
};