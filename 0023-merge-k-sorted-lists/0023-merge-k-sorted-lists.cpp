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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<>> pq;
        if(lists.size()==0)return nullptr;

        for(auto it:lists){
            while(it!=nullptr){
                pq.push(it->val);
                it=it->next;
            }
        }
       if(pq.size()==0)return nullptr;

        ListNode* head=new ListNode(pq.top());
        pq.pop();
        ListNode* temp=head;
        while(!pq.empty()){
            ListNode* z=new ListNode(pq.top());
            pq.pop();
            temp->next=z;
            temp=temp->next;
        }
        return head;

    }
};