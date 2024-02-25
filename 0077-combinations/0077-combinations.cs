public class Solution {
    public IList<IList<int>> Combine(int n, int k)
{
    IList<IList<int>> ans = new List<IList<int>>();
    IList<int> sofar = new List<int>();

    recur_combine(n, k, 1, sofar, ans);
    return ans;
}

public void recur_combine(int n, int k, int cur, IList<int> sofar, IList<IList<int>> ans)
{
    if (sofar.Count == k)
    {
        ans.Add(new List<int>(sofar));
        return;
    }

    for (int i = cur; i <= n; i++)
    {
        sofar.Add(i);

        recur_combine(n, k, i + 1, sofar, ans);

        if (sofar.Any())
            sofar.RemoveAt(sofar.Count - 1);
    }
}
}