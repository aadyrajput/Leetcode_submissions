class Solution {
private:
int fun(vector<int> &arr){
stack<int> st; int n=arr.size();
vector<int> left(n,0);
for(int i=0; i<n; i++){
    while(!st.empty() && arr[i]<=arr[st.top()]){
        st.pop();
    }
    if(st.empty())left[i]=0;
    else left[i]=st.top()+1;
    st.push(i);
}

stack<int> st2; 
vector<int> right(n,0);
for(int i=n-1; i>=0; i--){
    while(!st2.empty() && arr[i]<=arr[st2.top()]){
        st2.pop();
    }
    if(st2.empty())right[i]=n-1;
    else right[i]=st2.top()-1;
    st2.push(i);
}
int ans=INT_MIN;
for(int i=0; i<n; i++){
    int x=(right[i]-left[i]+1)*arr[i];
    ans=max(ans,x);
}
return ans;
}



public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int res=INT_MIN;
        int nn=matrix[0].size();
        vector<int> arr(nn,0);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='0') arr[j]=0;
                else arr[j]+=1;
            }
            int zz=fun(arr);
            res=max(res,zz);
        }


        return res;
    }
};