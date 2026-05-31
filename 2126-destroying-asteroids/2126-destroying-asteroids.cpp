class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        if(mass<asteroids[0])return false;
        long long sum=mass;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>sum)return false;
            sum+=asteroids[i];
        }
    return true;
    }
};