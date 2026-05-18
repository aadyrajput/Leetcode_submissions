#define ll long long int
class Solution {
public:
    const ll M1=1e9+7, M2=1e9+33;
    const ll rad1=26, rad2=27;

    pair<ll, ll> has(string x,int m){
        long long ans1=0, ans2=0,fact1=1, fact2=1;
        for(int i=m-1; i>=0; i--){
            ans1+=((x[i]-'a')*1ll*fact1)%M1;
            ans2+=((x[i]-'a')*1ll*fact2)%M2;
            fact1=(fact1*1ll*rad1)%M1;
            fact2=(fact2*1ll*rad2)%M2;
        }
    return {ans1%M1,ans2%M2};
    }
    
    bool fun(string &a,string &b){
        if(a==b)return true;
        ll n=a.size(), m=b.size();
        ll maxa1=1, maxa2=1;
        for(int i=0;i<m; i++){
            maxa1=(maxa1*1ll*rad1)%M1;
            maxa2=(maxa2*1ll*rad2)%M2;
        }
        pair<ll,ll> hasb=has(b,m);
        pair<ll,ll> hasa={0,0};

        for(int i=0;i<=n-m;i++){
            if(i==0){
                hasa=has(a,m);
            }
            else{
        hasa.first=((hasa.first*rad1)%M1-((a[i-1]-'a')*maxa1)%M1+(a[m-1+i]-'a')+M1)%M1;
        hasa.second=((hasa.second*rad2)%M2-((a[i-1]-'a')*maxa2)%M2+(a[m-1+i]-'a')+M2)%M2;
            }
            if(hasa.first==hasb.first && hasa.second==hasb.second)return true;
        }
    return false;
    }

    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        int ct=1;
        string aa=a;
        while(aa.size()<b.size()){
            aa+=a;
            ct++;
        }
        if(fun(aa,b))return ct;
        aa+=a; ct++;
        if(fun(aa,b))return ct;
        return -1;
    }
};