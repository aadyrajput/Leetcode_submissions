class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> m;
        int ptr=0;
        int ans=0;
        for(int i=0;i<fruits.size();i++){
            m[fruits[i]]++;
            if(m.size()>2){
                m[fruits[ptr]]--;
                if(m[fruits[ptr]]==0)m.erase(fruits[ptr]);
                ptr++;
            }
            ans=max(ans,i-ptr+1);
        }
        return ans;
    }
};