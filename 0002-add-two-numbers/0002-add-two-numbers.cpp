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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1,s2;
        ListNode* temp1=l1;
        while(temp1){
            char c=temp1->val+'0';
            s1.push_back(c);
            temp1=temp1->next;
        }
         ListNode* temp2=l2;
        while(temp2){
             char c=temp2->val+'0';
            s2.push_back(c);
            temp2=temp2->next;
        }
        string ans;
        int m=s1.size(); int n=s2.size();
        if(m<n){
            int z=n-m;
            while(z--)s1.push_back('0');
        }
        else if(m>n){
            int z=m-n;
            while(z--)s2.push_back('0');
        }

        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int carry=0; int nn=s1.size();
        for(int i=nn-1; i>=0; i--){
            int a=s1[i]-'0'; int b=s2[i]-'0';
            int c=a+b+carry;
            if(c<=9){string aa=to_string(c); ans+=aa; carry=0;}
            else{int cc=c%10; carry=c/10; string aa=to_string(cc); ans+=aa;}
        }
        if(carry>0){
            string aa=to_string(carry);
            ans+=aa;
        }
        //reverse(ans.begin(),ans.end());
        ListNode* head=new ListNode(ans[0]-'0');
        ListNode* temp=head;
        for(int i=1; i<ans.size(); i++){
            ListNode* tt=new ListNode(ans[i]-'0');
            temp->next=tt;
            temp=temp->next;
        }
        return head;


    }
};