class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int xmax=0; int ymax=0;
        int ct=0;
        for(int i=0;i<hBars.size()-1; i++){
            if(hBars[i+1]-hBars[i]==1)ct++;
            else{
               xmax=max(xmax,ct);   ct=0;
            }
        }
        xmax=max(xmax,ct);

       ct=0;
        for(int i=0;i<vBars.size()-1; i++){
            if(vBars[i+1]-vBars[i]==1)ct++;
            else{
               ymax=max(ymax,ct);   ct=0;
            }
        }
        ymax=max(ymax,ct);

        xmax+=2; ymax+=2;
        int mina=min(xmax,ymax);
        int res=mina*1ll*mina;
        return res;

    }
};