class Solution {
public:
    string longestPalindrome(string s) {
        string t ="#";
        for(auto it:s){
            t+=it; t+='#';
        }
        int n=t.size();
        vector<int> p(n,0);

        int l=0, r=-1;
        for(int i=0;i<n;i++){
            int k;
            if(i>r)k=1;
            else{
                int j=r-i+l;
                k=min(p[j],r-i);
            }

            while(i-k>=0 && i+k<n && t[i-k]==t[i+k]){
                k++;
            }
            k--;

            p[i]=k;
            if(i+k>r){
                l=i-k; r=i+k;
            }
        }

int best = 0, idx = 0;
for(int i=0;i<n;i++){
    if(p[i] > best){
        best = p[i];
        idx = i;
    }
}

return s.substr((idx - best + 1)/2, best);
    }
};