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
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;
        vector<int> v;
        ListNode* temp=head;
        while(temp){
            v.push_back(temp->val);
            if(temp->next==NULL) break;
            temp=temp->next->next;
        }
        ListNode* temp2=head->next;
         while(temp2){
            v.push_back(temp2->val);
            if(temp2->next==NULL)break;
            temp2=temp2->next->next;
        }

        ListNode* t=head;
        int i=0;
        while(t && i<v.size()){
            t->val=v[i]; i++;
            t=t->next;
        }
    return head;

    }
};