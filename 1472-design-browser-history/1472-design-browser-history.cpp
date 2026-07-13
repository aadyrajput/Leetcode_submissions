class Node{
    public:
    string url;
    Node* next;
    Node* prev;

    Node(string _url){
        this->url=_url;
        this->next=NULL;
        this->prev=NULL;
    }
};

class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp=new Node(url);
        curr->next=temp;
        temp->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(steps){
            if(curr->prev)curr=curr->prev;
            else break;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
         while(steps){
            if(curr->next)curr=curr->next;
            else break;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */