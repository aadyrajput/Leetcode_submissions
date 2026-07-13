/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      
      // step 1->insert copy nodes in between
      Node* temp=head;
      while(temp){
        Node* copyNode=new Node(temp->val);
        copyNode->next=temp->next;
        temp->next=copyNode;
        temp=temp->next->next;
      }

      // step 2-> connect random pointers of copy nodes
      temp=head;
      while(temp){
        Node* copyNode=temp->next;
        if(temp->random) copyNode->random=temp->random->next;
        temp=temp->next->next;
      }

      //step3->connect next pointers
      Node* newHead=new Node(-1);
      temp=head;
      Node* temp2=newHead;

      while(temp && temp2){
         temp2->next=temp->next;
         temp->next=temp->next->next;
          temp2=temp2->next;
          temp=temp->next;
      }

    return newHead->next;
    }
};