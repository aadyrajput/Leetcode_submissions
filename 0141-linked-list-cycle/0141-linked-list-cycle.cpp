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
        if(head==NULL || head->next==NULL) return false;
        map<ListNode*,int> m;
        ListNode* temp=head;
        while(temp){
            if(m.find(temp)!=m.end())return true;
            m[temp]++;
            temp=temp->next;
        }
    return false;
    }
};