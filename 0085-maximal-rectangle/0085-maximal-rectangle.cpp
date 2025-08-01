class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(); int n=matrix[0].size();
        vector<vector<int>> arr(m,vector<int>(n,0));
            for(int i=0;i<m; i++){
                for(int j=0;j<n; j++){
                    if(matrix[i][j]=='0')arr[i][j]=0;
                    else arr[i][j]=1;
                }
            }
    for(int i=1;i<m; i++){
        for(int j=0;j<n; j++){
            if(arr[i][j]==0) arr[i][j]=0;
            else arr[i][j]+=arr[i-1][j];
        }
    }

    int area=0;
    for(int i=0; i<m; i++){
        stack<int> st;
        for(int j=0; j<n; j++){
            while(!st.empty() && arr[i][st.top()]>=arr[i][j]){
                int ele=arr[i][st.top()]; st.pop();
                int nse=j;
                int pse=st.empty() ? -1 : st.top();
                area=max(area,ele*(nse-pse-1));
            }
            st.push(j);
        }
        while(!st.empty()){
            int ele=arr[i][st.top()]; st.pop();
            int nse=n;
            int pse=st.empty() ?-1:st.top();
            area=max(area,ele*(nse-pse-1));
        }
    }

return area;
    }
};