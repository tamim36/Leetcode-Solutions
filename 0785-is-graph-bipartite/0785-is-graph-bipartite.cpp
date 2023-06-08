class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
    vector<int> color(n, 0);

    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int x = q.front(); q.pop();
                int x_col = color[x];

                for (int i = 0; i < graph[x].size(); i++) {
                    int y = graph[x][i];
                    if (!color[y]) {
                        q.push(y);
                        color[y] = (-1) * x_col;
                    }
                    else if (color[y] == x_col) return false;
                }
            }
        }
        
    }

    return true;
    }
};