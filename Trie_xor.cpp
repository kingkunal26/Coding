class Node{
    Node *links[2];
    public:
    Node(){
        links[0]=NULL;
        links[1]=NULL;
    }
    bool contains(int bit)
    {
        return links[bit]!=NULL;
    }
    void put(int bit,Node *node)
    {
        links[bit]=node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
};
class Trie{
  Node *root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num)
    {
        Node *node=root;
        for(int j=31;j>=0;j--)
        {
            int bit=num>>j & 1;
            if(!node->contains(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num)
    {
        Node *node=root;
        
        int a=0;
        for(int j=31;j>=0;j--)
        {
            int bit=num>>j & 1;
            if(node==NULL)
            {
                return -1;
            }
            if(node->contains(!bit))
            {
                a+=!bit<<j;
                node=node->get(!bit);
            }
            else
            {
                a+=bit<<j;
                node=node->get(bit);
            }
        }
        return a;
        
    }
};

class Solution {
public:
    static bool mysort(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1]; 
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        vector<vector<int>> modifiedQueries;
        for(int i=0;i<queries.size();i++)
        {
            modifiedQueries.push_back({queries[i][0],queries[i][1],i});
        }
        sort(modifiedQueries.begin(),modifiedQueries.end(),mysort);
        sort(nums.begin(),nums.end());
        int idx=0;
        vector<int> ans(modifiedQueries.size());
        for(int i=0;i<queries.size();i++)
        {
            while(idx<nums.size() and nums[idx]<=modifiedQueries[i][1])
            {
                trie.insert(nums[idx]);
                idx++;
            }
            int mx=trie.getMax(modifiedQueries[i][0]);
            if(mx==-1)
            {
                ans[modifiedQueries[i][2]]=-1;
                continue;
            }
            ans[modifiedQueries[i][2]]=(mx^modifiedQueries[i][0]);
        }
        return ans;
    }
};