class Solution {
public:
    bool dfsIsPossibleBipartition(vector<int>& color, vector<vector<int>>& graph, int cur, int col) {
    color[cur] = col;
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!color[graph[cur][i]] &&
            !dfsIsPossibleBipartition(color, graph, graph[cur][i], -col))
            return false;
        else if (color[graph[cur][i]] != -col)
            return false;
    }

    return true;
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<int> color(n + 1, 0);
    vector<vector<int>> edges(n + 1);
    queue<int> q;

    for (auto dis : dislikes) {
        edges[dis[0]].push_back(dis[1]);
        edges[dis[1]].push_back(dis[0]);
    }

    for (int i = 1; i < n + 1; i++) {
        if (!color[i] && !dfsIsPossibleBipartition(color, edges, i, 1))
            return false;
    }

    return true;
}
};