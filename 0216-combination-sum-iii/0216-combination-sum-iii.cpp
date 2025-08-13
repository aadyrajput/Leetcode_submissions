class Solution {
private:
void fun(int k,int n,int start,vector<int>temp,vector<vector<int>> &ans){
   if(n==0 && k==0){
        ans.push_back(temp);
        return;
   }
   for(int i=start; i<=9; i++){
        if(i>n  || k<0)break;
        temp.push_back(i);
        fun(k-1,n-i,i+1,temp,ans);
         temp.pop_back();
   }

}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        fun(k,n,1,temp,ans);
        return ans;
    }
};