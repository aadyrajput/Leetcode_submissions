class Solution {
private:
vector<int> nsefun(vector<int>&v){
stack<int> st;
int n=v.size();
vector<int>nse(n);
for(int i=n-1;i>=0; i--){
    while(!st.empty() && v[st.top()]>=v[i]){
        st.pop();
    }
    if(st.empty())nse[i]=n;
    else nse[i]=st.top();
    st.push(i);
}
return  nse;
}

vector<int> psefun(vector<int>&v){
int n=v.size();
stack<int> st;
vector<int>pse(n);
for(int i=0; i<v.size(); i++){
    while(!st.empty() && v[st.top()]>=v[i]){
        st.pop();
    }
    if(st.empty())pse[i]=-1;
    else pse[i]=st.top();
    st.push(i);
}
return pse;
}

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse=nsefun(heights);
        vector<int> pse=psefun(heights);
        int ans=0;
        for(int i=0;i<heights.size(); i++){
            int left=i-pse[i]-1;
            int right=nse[i]-i-1;
            int len=left+right+1;
            int res=len*1ll*heights[i];
            ans=max(ans,res);
        }
        return ans;
        
    }
};