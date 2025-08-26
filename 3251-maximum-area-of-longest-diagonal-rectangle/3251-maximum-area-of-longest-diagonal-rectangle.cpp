class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int len=0;
        int area=0;
        for(int i=0;i<dimensions.size(); i++){
            int l=dimensions[i][0]; int w=dimensions[i][1];
           int x=(l*l)+(w*w); int a=l*w;
           if(x>len){
            len=x;
            area=a;
           }
           else if(x==len) area=max(a,area);
           }
        return area;
    }
};