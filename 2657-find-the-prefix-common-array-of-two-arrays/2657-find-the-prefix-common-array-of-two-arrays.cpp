class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> ans(n,0);
        int ct=0;
        map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.find(A[i])!=m.end()){
                ct++;
            }
            else m[A[i]]++;
            if(m.find(B[i])!=m.end()){
                ct++;
            }
            else m[B[i]]++;
            ans[i]=ct;
        }
        return ans;
    }
};