class Solution {
public:
     vector<int> next_smaller(vector<int> &arr){
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty())ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prev_smaller(vector<int> &arr){     
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
     }

    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> temp(cols,0);

        for(int i=0;i<cols;i++){
            temp[i]=matrix[0][i]-'0';
        }
        vector<int> prev=prev_smaller(temp);
        vector<int> next=next_smaller(temp);
        long long ans=0;
        for(int i=0;i<cols;i++){
            int z=next[i]-prev[i]-1;
            ans=max(ans,z*1ll*temp[i]);
        }

        for(int i=1;i<rows; i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='0')temp[j]=0;
                else temp[j]++;
            }
            vector<int> prev=prev_smaller(temp);
            vector<int> next=next_smaller(temp);
            for(int k=0;k<cols;k++){
                int z=next[k]-prev[k]-1;
                ans=max(ans,z*1ll*temp[k]);
            }
        }
    return ans;
    }
};