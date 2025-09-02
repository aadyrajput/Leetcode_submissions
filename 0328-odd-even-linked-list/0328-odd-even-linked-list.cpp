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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)return head;
        ListNode* temp=head;
        vector<int> v1,v2; int flag=0;        
        while(temp){
            if(flag==0){v1.push_back(temp->val); flag=1;}
            else{v2.push_back(temp->val); flag=0;}
            temp=temp->next;
        }
        for(auto it:v2)v1.push_back(it);
        temp=head; int i=0;
        while(temp){
            temp->val=v1[i];
            temp=temp->next;i++;
        }
        return head;
    }
};