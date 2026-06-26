class Twitter {
public:
    unordered_map<int,unordered_set<int>> follows;
    unordered_map<int,set<pair<int,int>>> m;
    int timer=0;

    Twitter() {    
    }
    void postTweet(int userId, int tweetId) {
        timer++;
        while(m[userId].size()==10){
                m[userId].erase(m[userId].begin());
            }
        m[userId].insert({timer,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(auto it:follows[userId]){
            for(auto it:m[it]){
                pq.push({it.first,it.second});
            }
        }
        for(auto it:m[userId])pq.push({it.first,it.second});

        while(pq.size()>10)pq.pop();

        while(!pq.empty()){
            ans.push_back(pq.top().second); pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */