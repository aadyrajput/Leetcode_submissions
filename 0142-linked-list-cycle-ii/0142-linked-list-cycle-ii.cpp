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
    ListNode *detectCycle(ListNode *head) {
       if(head==NULL || head->next==NULL) return NULL;
        map<ListNode*,int> m;
        ListNode* temp=head;
        while(temp){
            if(m.find(temp)!=m.end())return temp;
            m[temp]++;
            temp=temp->next;
        }
    return NULL;
    }
};