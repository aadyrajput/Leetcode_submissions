class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
     unordered_set<int> s;
     int n=arr.size();
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
        int a=arr[i]; int b=0;
        for(int j=i-1; j>=0; j--){
            a= a| arr[j];
            b=b|arr[j];
            if(a==b)break;
            s.insert(a);
        }
    }
    return s.size();

    }
};