struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
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
        for(int i=31; i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int findmax(int x){
        int ans=0;
        Node* node=root;
        for(int i=31; i>=0; i--){
            int bit=(x>>i)&1;
            int want=1-bit;
            if(node->containsKey(want)){
                ans=ans|(1<<i);
                node=node->get(want);
            }
            else{
                node=node->get(bit);
            }
        }
    return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int z=queries.size();
        vector<int> ans(z,-1);
        
        vector<pair<int,pair<int,int>>> qr;
        for(int i=0;i<z;i++){
            qr.push_back({queries[i][1],{i,queries[i][0]}});
        }
        sort(qr.begin(),qr.end());

        sort(nums.begin(),nums.end());
        int j=0;
        Trie tr;

        for(int i=0;i<z;i++){
            int maxa=qr[i].first;
            int ind=qr[i].second.first;
            int x=qr[i].second.second;
            while(j<nums.size()){
                if(nums[j]>maxa)break;
                tr.insert(nums[j]);
                j++;
            }
            if(j==0)ans[ind]=-1;
            else ans[ind]=tr.findmax(x);
        }

        return ans;
    }
};