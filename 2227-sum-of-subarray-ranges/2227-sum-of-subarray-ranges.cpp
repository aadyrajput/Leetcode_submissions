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

private:
vector<int> nge(vector<int>&arr){
    stack<int> st; int n=arr.size();
    vector<int>v(n);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty())v[i]=n;
        else v[i]=st.top();
        st.push(i);
    }
    return v;
}

vector<int> pge(vector<int>&arr){
    stack<int> st2; int n=arr.size();
    vector<int>v(n);
    for(int i=0; i<n; i++){
        while(!st2.empty() && arr[st2.top()]<arr[i]){
            st2.pop();
        }
        if(st2.empty())v[i]=-1;
        else v[i]=st2.top();
        st2.push(i);
    }
    return v;
}



public:
    long long subArrayRanges(vector<int>& nums) {
    int n=nums.size();
     vector<int> nseA=nse(nums);
     vector<int> pseA=pse(nums);

      vector<int> ngeA=nge(nums);
     vector<int> pgeA=pge(nums);
     long long ans1=0; 
     for(int i=0;i<nums.size(); i++){
        long long a=nseA[i]-i;
        long long b=i-pseA[i];
      ans1=(ans1+(long long)nums[i]*a*b);
     }
      long long ans2=0; 
     for(int i=0;i<nums.size(); i++){
        long long a=ngeA[i]-i;
        long long b=i-pgeA[i];
      ans2=(ans2+(long)nums[i]*a*b);
     }
    return ans2-ans1;
    }
};