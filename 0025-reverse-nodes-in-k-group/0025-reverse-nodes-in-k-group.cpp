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
ListNode* reverse(ListNode* x){
     if(x==NULL || x->next==NULL)return x;
        ListNode* prev=NULL;
        ListNode* curr=x;
        while(curr){
            ListNode* z=curr->next;
            curr->next=prev;
            prev=curr;
            curr=z;
        }
    return prev;
}

    ListNode* giveKthNode(ListNode* z,int k){
        int ct=0;
        while(z){
            ct++;
            if(ct==k) return z;
            z=z->next;
        }
        return NULL;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* nextNode;
        ListNode* prevNode=NULL;

        while(temp){
            ListNode* kthNode=giveKthNode(temp,k);
            if(kthNode==NULL){
                if(prevNode)prevNode->next=temp;
                break;
            }
            nextNode=kthNode->next;
            kthNode->next=NULL;
            ListNode* rev=reverse(temp);
            
            if(temp==head){
                head=kthNode;
            }
            else{
                prevNode->next=kthNode;
            }

            prevNode=temp;
            temp=nextNode;
        }

    return head;

    }
};