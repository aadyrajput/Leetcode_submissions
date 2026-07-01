class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
     int n=pref.size();
     vector<int> arr(n,0);
    arr[0]=pref[0];
    int has=pref[0];
    for(int i=1;i<n;i++){
        arr[i]=has^pref[i];
        has=pref[i];
    }

    return arr;
    }
};