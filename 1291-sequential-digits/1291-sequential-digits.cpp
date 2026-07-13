class Solution {
public:
    int digits(int z){
        int ct=0;
        while(z){
            ct++;
            z/=10;
        }
        return ct;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        int ll=digits(low); int hh=digits(high);

        for(int i=ll; i<=hh; i++){
            for(int j=1; j<=9; j++){
                int no_of_digits=i;
                int num=0; int st=j;
                while(no_of_digits--){
                    if(st>9)break;
                    num=(num*10);
                    num+=st;
                    st++;
                }
                if(no_of_digits==-1)v.push_back(num);
            }
        }

    vector<int> ans;
    for(auto it:v){
        if(it< low)continue;
        if(it>high)break;
        ans.push_back(it);
    }

    return ans;

    }
};