class Solution {
public:
    vector<int> ans;
    void mergeSort(int lo,int hi,vector<pair<int,int>>&v){
        if(lo>=hi)return;
        int mid=(lo+hi)/2;
        mergeSort(lo,mid,v);
        mergeSort(mid+1,hi,v);
        merge(lo,mid,hi,v);
    }

    void merge(int lo,int mid,int hi,vector<pair<int,int>>&v){
        int ct=0;
        int le=lo,ri=mid+1;
        vector<pair<int,int>> temp;
        while(le<=mid && ri<=hi){
            if(v[le].first<=v[ri].first){ans[v[le].second]+=ct;  temp.push_back(v[le]); le++;}
            else{ct++;  temp.push_back(v[ri]); ri++;}
        }
        while(le<=mid){ans[v[le].second]+=ct; temp.push_back(v[le]); le++;}
        while(ri<=hi){temp.push_back(v[ri]); ri++;}

        for(int i=lo;i<=hi;i++){
            v[i]=temp[i-lo];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
          ans.resize(n,0);
        mergeSort(0,n-1,v);
        return ans;
    }
};