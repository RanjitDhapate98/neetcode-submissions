/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*>&mp){
        if(node==NULL){
            return NULL;
        }
        if(mp.find(node)!=mp.end()){
            return mp[node];
        }
        Node* newnode=new Node(node->val);
        mp[node]=newnode;
        for(auto i:node->neighbors){
            newnode->neighbors.push_back( dfs(i,mp));
           
        }
        return newnode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        return dfs(node,mp);
    }
};
