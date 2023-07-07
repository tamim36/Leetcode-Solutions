class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return { 0 };
        vector<int> indg(n, 0);
    vector<vector<int>> adj(n);
    queue<int> q;
    int cnt = n;

    for (auto edge : edges) {
        int a = edge[0], b = edge[1];
        indg[a]++, indg[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (indg[i] == 1) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int sz = q.size();
        if (cnt <= 2) {
                while (!q.empty())
                {
                    ans.push_back(q.front()); q.pop();
                }
                break;
            }
        
        for (int i = 0; i < sz; i++) {
            int top = q.front(); q.pop();
            cnt--;
            
            for (auto node : adj[top]) {
                if (--indg[node] == 1)
                    q.push(node);
            }
        }
        
    }

    return ans;
    }
};