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
    Node* cloneGraph(Node* node) {
        if (!node)
        return node;
    Node* root = new Node(node->val);
    if (node->neighbors.empty())
        return root;
        //cout << "root: " << root->val << endl;
    queue<Node*> q, nq;
    unordered_map<int, Node*> mp;
    mp[root->val] = root;
    q.push(node);
    nq.push(root);

    while (!q.empty())
    {
        Node* top = q.front(); q.pop();
        Node* newTop = nq.front(); nq.pop();
        //cout << "print: " << newTop->val << endl;

        for (Node* neigh : top->neighbors) {
            if (!mp.count(neigh->val)) {
                Node* newNode = new Node(neigh->val);
                mp[newNode->val] = newNode;
                //cout << "newtop: " << newTop->val << " newNode: " << newNode->val << endl;
                newTop->neighbors.push_back(newNode);
                q.push(neigh);
                nq.push(newNode);
            }
            else {
                newTop->neighbors.push_back(mp[neigh->val]);
            }
        }
    }

    return root;
    }
};