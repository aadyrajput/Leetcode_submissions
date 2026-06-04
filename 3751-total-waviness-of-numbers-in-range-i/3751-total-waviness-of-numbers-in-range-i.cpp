class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ct=0;
        for(int i=num1; i<=num2; i++){
            if(i<100)continue;
            vector<int> v;
            int z=i;
            while(z){
                v.push_back(z%10);
                z/=10;
            }
            reverse(v.begin(),v.end());

            for(int j=1;j<v.size()-1; j++){
                if(v[j]>v[j-1] && v[j]>v[j+1]) ct++;
                else if(v[j]<v[j-1] && v[j]<v[j+1]) ct++;
            }
        }
        return ct;

    }
};