class Node{
    Node *links[2];
    public:
    bool containsKey(int no)
    {
        return links[no]!=NULL;
    }
    Node *get(int no)
    {
       return links[no]; 
    }
    void put(int no,Node *node)
    {
        links[no]=node;
    }
};
class Trie{
    private:
    Node *root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node *node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }

    }
    
    int maxXOR(int num)
    {
        Node *node=root;
        int maxn=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            //we have to find the opposite to maximize xor
            if(node->containsKey(1-bit))
            {
                maxn+=(1<<i);
                node=node->get(1-bit);
                
            }
            else
                node=node->get(bit);

        }
        return maxn;

    }
    
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.   
    Trie trie;
    for(auto &it:arr1)
    {
        trie.insert(it);
    }
    int maxi=0;
    for(auto &it:arr2)
        maxi=max(maxi,trie.maxXOR(it));
    return maxi;
    
}