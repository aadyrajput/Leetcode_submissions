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
    ListNode* rotateRight(ListNode* head, int k) {
     ListNode* temp=head;
     if(k==0 || head==NULL)return head;
     vector<int> v,v2;
     while(temp){
        v.push_back(temp->val);
        temp=temp->next;
     }
     int n=v.size(); k=k%n;
     for(int i=n-k; i<n;i++)v2.push_back(v[i]);
     for(int i=0;i<n-k; i++)v2.push_back(v[i]);
     int i=0; temp=head;
     while(temp){
        temp->val=v2[i];
        i++; temp=temp->next;
     }
return head;
    }
};