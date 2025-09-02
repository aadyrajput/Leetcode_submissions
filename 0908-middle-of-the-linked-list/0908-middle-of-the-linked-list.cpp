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
        if(head==NULL)return NULL;
        vector<int> v;
        ListNode* temp=head;
        while(temp){v.push_back(temp->val); temp=temp->next;}
        int n=v.size();
        int tar=n/2;
        int ct=0; temp=head;
        while(temp){
            if(ct==tar) break;
            temp=temp->next; ct++;
        }
        head=temp;
        return head;
    }
};