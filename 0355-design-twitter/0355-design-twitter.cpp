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
            set<pair<int,int>> temp=m[it];
            for(int i=0;i<10;i++){
                if(temp.empty())break;
                 auto it=*(--temp.end());
                 temp.erase(--temp.end());
                int a=it.first, b=it.second;
                if(pq.size()==10 && pq.top().first>a)break;
                while(pq.size()==10)pq.pop();
                pq.push({a,b});
            }
        }

        set<pair<int,int>> temp=m[userId];
            for(int i=0;i<10;i++){
                if(temp.empty())break;
                auto it=*(--temp.end());
                temp.erase(--temp.end());
                int a=it.first, b=it.second;
                if(pq.size()==10 && pq.top().first>a)break;
                while(pq.size()==10)pq.pop();
                pq.push({a,b});
            }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
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