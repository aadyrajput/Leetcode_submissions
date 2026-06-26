class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        map<int,int> m;
        for(auto it:hand)m[it]++;
        for(auto it:m)pq.push({it.first,it.second});

        while(!pq.empty()){
            vector<pair<int,int>> v;
            int start=pq.top().first;
            for(int i=0;i<groupSize;i++){
                if(pq.empty())return false;
                int z=pq.top().first, ct=pq.top().second;
                pq.pop();
                if(z!=start+i) return false;
                if(ct>1) v.push_back({z,ct-1});
            }
            for(auto it:v)pq.push({it.first,it.second});
        }
        return true;


    }
};