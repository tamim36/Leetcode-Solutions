class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> partition;
        unordered_set<int> isVisited;

        for (int i = 0; i < graph.size(); i++) {
            for (auto node : graph[i])
                adjList[i].push_back(node);
        }

        queue<int> q;
        for (int i = 1; i <= 100; i++) {
            if (!adjList[i].empty() && !isVisited.count(i)) {
                q.push(i);
                partition[i] = 1;

                while (!q.empty()) {
                    int curNode = q.front();
                    q.pop();

                    if (isVisited.count(curNode))
                        continue;

                    isVisited.insert(curNode);
                    int adjPartitionNo = partition[curNode] == 1 ? 2 : 1;

                    for (auto adjNode : adjList[curNode]) {
                        q.push(adjNode);

                        if (partition[adjNode] != 0 &&
                            partition[adjNode] != adjPartitionNo) {
                            // cout << "Partition[adjNode]: " <<
                            // partition[adjNode] << "  adjPartionNo: " <<
                            // adjPartitionNo;
                            return false;
                        }

                        partition[adjNode] = adjPartitionNo;
                    }
                }
            }
        }

        return true;
    }
};