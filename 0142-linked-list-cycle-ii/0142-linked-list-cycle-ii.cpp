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
     map<ListNode*, bool> vis;
     ListNode* temp=head;
     bool flag=false;
     while(temp!=NULL){
        if(vis[temp]){flag=true;break;}
        vis[temp]=true;
        temp=temp->next;
     }
     if(flag) return temp;
     return NULL;
    }
};