class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int ans=0;
        int carry=0;
        for(int i=n-1;i>=1;i--){
            if(s[i]=='0'){
                if(carry==0)ans++;
                else ans+=2;
            }
            else{
                if(carry==0){carry=1; ans+=2;}
                else{carry=1; ans++;}
            }
        }

    if(carry==1)ans++;
    return ans;
    }
};