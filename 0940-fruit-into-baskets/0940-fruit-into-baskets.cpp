class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     map<int,int> m;
    int ans=0;
    int left=0;
    for(int i=0;i<fruits.size(); i++){
        if(m.find(fruits[i])!=m.end()){
            m[fruits[i]]++;}
        else{
            while(m.size()>1){
                if(m[fruits[left]]>=2)  m[fruits[left]]--;
                else m.erase(fruits[left]);
                left++;
            }
            m[fruits[i]]++;
         }
         ans=max(ans,i-left+1);
     }

     return ans;   
    }
};