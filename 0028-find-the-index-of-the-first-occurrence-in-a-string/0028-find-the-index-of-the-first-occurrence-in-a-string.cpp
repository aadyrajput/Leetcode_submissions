class Solution {
public:
    int M=1e9+7;
    int radii=26;

    int fun(string &s, int m){
        int mult=1;
        int ans=0;
        for(int i=m-1;i>=0; i--){
            ans=(ans+ ((s[i]-'a')*1ll*mult)%M )%M;
            mult=(mult*1ll*radii)%M;
        }
    return ans;
    }

    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        int hasN=fun(needle,m);

        int maxa=1;
        for(int i=0;i<m;i++){
            maxa=(maxa*1ll*radii)%M;
        }

        int hasH=0;
        for(int i=0;i<=n-m;i++){
            if(i==0){
                hasH=fun(haystack,m);
            }
            else{
                hasH=((hasH*1ll*radii)%M -((haystack[i-1]-'a')*1ll*maxa)%M + (haystack[m+i-1]-'a')%M  + M)%M;
            }
            if(hasH==hasN)return i;
        }

    return -1;
    }
};