class RideSharingSystem {
public:
    queue<int> rider,driver;
    set<int> st;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        st.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);   
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty() || driver.empty()){
            return {-1,-1};
        }
        int x=rider.front();
        int y=driver.front();
        rider.pop(); driver.pop();
        st.erase(x);
        return {y,x};
    }
    
    void cancelRider(int riderId){
        if(st.find(riderId)==st.end())return;
        st.erase(riderId);
        queue<int> q;
        while(!rider.empty()){
            int x=rider.front();
            rider.pop();
            if(x==riderId)continue;
            else q.push(x);
        }
        rider=q;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */