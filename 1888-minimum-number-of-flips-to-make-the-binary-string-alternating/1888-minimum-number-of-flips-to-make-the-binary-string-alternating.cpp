class Solution {
public:
    int minFlips(string s) {
      int n=s.size();
      string ss=s+s;

    //patern1--  10101010
    //patern2--  01010101

    int pt1=0; int pt2=0;
    for(int i=0;i<n;i++){
        if(i%2==0 && s[i]=='0')pt1++;
        else if(i%2==1 && s[i]=='1')pt1++;

        if(i%2==0 && s[i]=='1')pt2++;
        else if(i%2==1 && s[i]=='0')pt2++;
    }
    int ans=min(pt1,pt2);

    for(int i=n; i<ss.size(); i++){
        if((i-n)%2==0 && ss[i-n]=='0') pt1--;
        if((i-n)%2==1 && ss[i-n]=='1') pt1--;

        if((i-n)%2==0 && ss[i-n]=='1') pt2--;
        if((i-n)%2==1 && ss[i-n]=='0') pt2--;

        if(i%2==0 && ss[i]=='0') pt1++;
        if(i%2==1 && ss[i]=='1') pt1++;

        if(i%2==0 && ss[i]=='1') pt2++;
        if(i%2==1 && ss[i]=='0') pt2++;

        ans=min(ans,min(pt1,pt2));
    }
    return ans;



    
    }
};