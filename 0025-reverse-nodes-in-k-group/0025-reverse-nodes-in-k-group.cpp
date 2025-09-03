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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v,ans;
        ListNode* temp=head;
        while(temp){
        v.push_back(temp->val);
        temp=temp->next;
        }
        int n=v.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(v[i]);
            if(st.size()==k){
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        vector<int> tt;
        while(!st.empty()){
            tt.push_back(st.top()); st.pop();
        }
        reverse(tt.begin(),tt.end());
        for(auto it:tt)ans.push_back(it);
        int i=0;
        temp=head;
        while(temp){
            temp->val=ans[i];
            i++; temp=temp->next;
        }
        return head;   
    }
};