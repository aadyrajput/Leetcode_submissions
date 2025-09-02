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
        if(head==NULL)return NULL;
        map<ListNode*,bool> m;
        ListNode* temp=head;
        bool flag=false;
        while(temp){
            if(m[temp]){flag=true; break;}    
            m[temp]=true;
            temp=temp->next; 
        }
        if(flag)return temp;
        return NULL;
    }
};