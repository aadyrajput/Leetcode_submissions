class LFUCache {
public:
    class Node{
    public:
        int key,val,freq;
        Node *prev,*next;

        Node(int k,int v){
            key=k;
            val=v;
            freq=1;
            prev=next=NULL;
        }
    };

    class List{
    public:
        int sz;
        Node *head,*tail;

        List(){
            sz=0;
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;
        }

        void addNode(Node *x){
            Node *t=head->next;
            x->next=t;
            x->prev=head;
            head->next=x;
            t->prev=x;
            sz++;
        }

        void deleteNode(Node *x){
            Node *p=x->prev;
            Node *n=x->next;
            p->next=n;
            n->prev=p;
            sz--;
        }
    };

    int cap,minFreq;

    unordered_map<int,Node*> mp;
    unordered_map<int,List*> freq;

    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
    }

    void update(Node *x){

        int f=x->freq;

        freq[f]->deleteNode(x);

        if(f==minFreq && freq[f]->sz==0)
            minFreq++;

        x->freq++;

        if(freq.find(x->freq)==freq.end())
            freq[x->freq]=new List();

        freq[x->freq]->addNode(x);
    }

    int get(int key) {

        if(mp.find(key)==mp.end())
            return -1;

        Node *x=mp[key];

        update(x);

        return x->val;
    }

    void put(int key, int value) {

        if(cap==0)
            return;

        if(mp.find(key)!=mp.end()){

            Node *x=mp[key];
            x->val=value;
            update(x);
            return;
        }

        if(mp.size()==cap){

            List *lst=freq[minFreq];
            Node *del=lst->tail->prev;

            lst->deleteNode(del);
            mp.erase(del->key);
            delete del;
        }

        Node *x=new Node(key,value);

        minFreq=1;

        if(freq.find(1)==freq.end())
            freq[1]=new List();

        freq[1]->addNode(x);

        mp[key]=x;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */