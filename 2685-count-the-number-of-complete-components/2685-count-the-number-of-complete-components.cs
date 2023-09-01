public class Solution {
    public int CountCompleteComponents(int n, int[][] edges) {
        IList<IList<int>> adj = new List<IList<int>>(n);
            for (int i = 0; i < n; i++)
                adj.Add(new List<int>());

            int[] vis = new int[n];
            Queue<int> q = new Queue<int>();
            int cnt = 0;

            foreach (var edge in edges)
            {
                adj[edge[0]].Add(edge[1]);
                adj[edge[1]].Add(edge[0]);
            }

            for (int i = 0; i < n; i++)
            {
                if (vis[i] == 1) continue;

                q.Enqueue(i);
                vis[i] = 1;
                int conNodes = adj[i].Count;
                bool isConnected = true;
                int numNodes = 0;

                while (q.Count > 0)
                {
                    int cur = q.Dequeue();
                    numNodes++;

                    if (isConnected && adj[cur].Count != conNodes)
                        isConnected = false;

                    foreach (var nei in adj[cur])
                    {
                        if (vis[nei] == 1) continue;
                        q.Enqueue(nei);
                        vis[nei] = 1;
                    }
                }

                if (numNodes - 1 == conNodes && isConnected)
                    cnt++;
            }

            return cnt;
    }
}