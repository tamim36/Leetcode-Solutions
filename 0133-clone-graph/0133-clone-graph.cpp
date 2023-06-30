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
    void dfs_toCloneGraph(Node* node, Node* root, unordered_map<int, Node*>& mp) {
    if (!node || node->neighbors.empty())
        return;
        
    for (Node* neigh : node->neighbors) {
        if (!mp.count(neigh->val)) {
            Node* newNode = new Node(neigh->val);
            mp[newNode->val] = newNode;
            root->neighbors.push_back(newNode);
            dfs_toCloneGraph(neigh, newNode, mp);
        }
        else
            root->neighbors.push_back(mp[neigh->val]);
    }
}

Node* cloneGraph(Node* node) {
    if (!node)
        return node;
    Node* root = new Node(node->val);
    if (node->neighbors.empty())
        return root;

    unordered_map<int, Node*> mp;
    mp[root->val] = root;
    dfs_toCloneGraph(node, root, mp);
    return root;
}
};