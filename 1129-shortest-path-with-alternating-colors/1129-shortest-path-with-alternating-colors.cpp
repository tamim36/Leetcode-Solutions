class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redAdj(n), blueAdj(n);
    vector<int> path(n, -1), visNode(n, 0);
    queue<pair<int, int>> q; // node, color
    int cnt = 0;

    for (auto r : redEdges) { if (r[0] || r[1]) redAdj[r[0]].push_back(r[1]); }
    for (auto b : blueEdges) { if (b[0] || b[1]) blueAdj[b[0]].push_back(b[1]); }

    q.push({ 0, 1 });
    q.push({ 0, 0 });
    path[0] = 0;
    visNode[0]++;

    while (!q.empty()) {
        int sz = q.size();
        cnt++;
        for (int i = 0; i < sz; i++) {
            int cur = q.front().first; int isRed = q.front().second; q.pop();

            if (isRed) {
                for (int child : redAdj[cur]) {
                    if (visNode[child] < 200) {
                        q.push({ child, 0 });
                        visNode[child]++;
                        if (path[child] == -1) path[child] = cnt;
                    }
                }
            }
            else {
                for (int child : blueAdj[cur]) {
                    if (visNode[child] < 200) {
                        q.push({ child, 1 });
                        visNode[child]++;
                        if (path[child] == -1) path[child] = cnt;
                    }
                }
            }
        }
    }

    return path;
    }
};