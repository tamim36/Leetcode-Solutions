class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1, 0);
    vector<vector<int>> edges(n+1);
    queue<int> q;

    for (auto dis : dislikes) {
        edges[dis[0]].push_back(dis[1]);
        edges[dis[1]].push_back(dis[0]);
    }

    for (int i = 1; i < n + 1; i++) {
        if (!color[i]) { q.push(i); color[i] = 1; }

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int cur_col = color[cur];

            for (int j = 0; j < edges[cur].size(); j++) {
                int child = edges[cur][j];
                if (!color[child]) { q.push(child); color[child] = -cur_col; }
                else if (cur_col == color[child]) return false;
            }
        }
    }

    return true;
    }
};