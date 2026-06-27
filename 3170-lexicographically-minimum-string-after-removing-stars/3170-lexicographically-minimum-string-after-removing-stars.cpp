class Solution {
public:
    struct comp {
    bool operator()(const pair<char,int>& a, const pair<char,int>& b) const {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

    string clearStars(string s) {
     priority_queue<pair<char,int>,vector<pair<char,int>>,comp> pq;
     int n=s.size();

     for(int i=0;i<n;i++){
        if(s[i]!='*'){
            pq.push({s[i],i});
        }
        else{
            s[i]='Z'; s[pq.top().second]='Z';
            pq.pop();
        }
     }
    string res="";
    for(auto it:s){
        if(it!='Z')res+=it;
    }
    return res;

    }
};