class LRUCache {
public:
    class Node{
        public:
        int key,val;
        Node* prev;
        Node* next;
        Node(int key,int val){
        this->key=key;
        this->val=val;
        prev=NULL; next=NULL;
        }
    };

    map<int,Node*> m;
    int cap; 
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    LRUCache(int capacity) {    
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node* z){
        Node* temp=head->next;
        z->next=temp;
        z->prev=head;

        head->next=z;
        temp->prev=z;
    }

    void deleteNode(Node* z){
        Node* prevv=z->prev;
        Node* nextt=z->next;
        prevv->next=nextt;
        nextt->prev=prevv;
    }
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        Node* z=m[key];
        int ans=z->val;
        m.erase(key);
        deleteNode(z);
        addNode(z);
        m[key]=head->next;
        return ans;
    }  
    
    void put(int key, int value) {
       if(m.find(key)!=m.end()){
            Node* curr=m[key];
            m.erase(key);
            deleteNode(curr);
       }
       if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
       }
       addNode(new Node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */