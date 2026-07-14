struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31; i>=0; i--){
            int bit=(num>>i) &1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    };

    int findmax(int num){
        Node* node=root;
        int maxa=0;
        for(int i=31; i>=0; i--){
            int z=(num>>i) &1;
            int want=1-z;
            if(node->containsKey(want)){
                maxa=maxa|(1<<i);
                node=node->get(want);
            }
            else{
                node=node->get(z);
            }
        }
    return maxa;
    }
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
            Trie tr;
            for(auto it:nums){
                tr.insert(it);
            }        
            int ans=0;
        for(int i=0;i<nums.size(); i++){
            int z=tr.findmax(nums[i]);
            ans=max(ans,z);
        }
        return ans;
    }
};