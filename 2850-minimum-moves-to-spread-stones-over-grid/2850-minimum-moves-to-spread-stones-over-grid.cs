public class Solution {
    public int MinimumMoves(int[][] grid)
{
    int[] starter = new int[9];
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        starter[i*3 +j] = grid[i][j];
    }
}

var target = new int[] { 1, 1, 1, 1, 1, 1, 1, 1, 1};
Queue<int[]> q = new Queue<int[]>();
ISet<string> visited = new HashSet<string>();

q.Enqueue(starter);
visited.Add(ArrayToString(starter));

int moves = 0;
while (q.Any())
{
    int sz = q.Count;
    for (int i = 0; i < sz; i++)
    {
        int[] cur = q.Dequeue();
        if (cur.SequenceEqual(target))
            return moves;

        for (int j = 0; j < 9; j++)
        {
            if (cur[j] > 1)
            {
                foreach (var adj in getAdjacentsMimimumMoves(j))
                {
                    int[] newState = (int[])cur.Clone();
                    newState[j]--;
                    newState[adj]++;

                    string state = ArrayToString(newState);
                    if (!visited.Contains(state))
                    {
                        q.Enqueue(newState);
                        visited.Add(state);
                    }
                }
            }
        }
    }
    moves++;
}


return moves;
}

public IList<int> getAdjacentsMimimumMoves(int index)
{
    IList<int> adj = new List<int>();
    if (index % 3 != 0) adj.Add(index - 1);
    if (index % 3 != 2) adj.Add(index + 1);
    if (index / 3 != 0) adj.Add(index - 3);
    if (index / 3 != 2) adj.Add(index + 3);
    return adj;
}

public string ArrayToString(int[] ara)
{
    string res = "";
    foreach (int num in ara)
    {
        res += num;
    }
    return res;
}
}