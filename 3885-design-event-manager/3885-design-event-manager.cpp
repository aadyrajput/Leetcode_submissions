class EventManager {
public:
    map<int,int> m;
    priority_queue<pair<int,int>> pq;

    EventManager(vector<vector<int>>& events) {
        for(auto it:events){
            m[it[0]]=it[1];
            pq.push({it[1],-it[0]});
        }    
    }
    
    void updatePriority(int eventId, int newPriority) {
        m[eventId]=newPriority;
        pq.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        
        while(!pq.empty()){
            int pr=pq.top().first;
            int id=-pq.top().second;
            if(m[id]==pr){
                pq.pop();
                m.erase(id);
                return id;
            }
            pq.pop();
        }

        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */