class Solution {
private:
vector<int> nse(vector<int>&arr){
    stack<int> st; int n=arr.size();
    vector<int>v(n);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty())v[i]=n;
        else v[i]=st.top();
        st.push(i);
    }
    return v;
}

vector<int> pse(vector<int>&arr){
    stack<int> st2; int n=arr.size();
    vector<int>v(n);
    for(int i=0; i<n; i++){
        while(!st2.empty() && arr[st2.top()]>arr[i]){
            st2.pop();
        }
        if(st2.empty())v[i]=-1;
        else v[i]=st2.top();
        st2.push(i);
    }
    return v;
}

public:
    int sumSubarrayMins(vector<int>& arr) {
     int n=arr.size();
     vector<int> nseA=nse(arr);
     vector<int> pseA=pse(arr);
     long ans=0; int M=1e9+7;
     for(int i=0;i<arr.size(); i++){
        int a=nseA[i]-i;
        int b=i-pseA[i];
      ans=(ans+(long)arr[i]*a*b)%M;
     }
     return (int)ans;

    }
};