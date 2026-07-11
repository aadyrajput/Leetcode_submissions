class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL, *curr = head;

        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;

        // Find middle
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* second = reverse(slow->next);

        // Compare
        ListNode *first = head;
        ListNode *temp = second;

        while(temp){
            if(first->val != temp->val){
                reverse(second);      // Restore list
                return false;
            }
            first = first->next;
            temp = temp->next;
        }

        // Restore list
        reverse(second);

        return true;
    }
};