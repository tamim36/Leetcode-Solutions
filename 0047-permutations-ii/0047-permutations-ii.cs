public class Solution {
    public IList<IList<int>> PermuteUnique(int[] nums)
{
    IList<IList<int>> res = new List<IList<int>>();
    recur_permuteUnique(res, 0, nums);
    return res;
}

private void recur_permuteUnique(IList<IList<int>> res, int idx, int[] nums)
{
    if (idx == nums.Length)
    {
        res.Add(nums.ToList());
        return;
    }

    ISet<int> visited = new HashSet<int>();
    for (int i = idx; i < nums.Length; i++)
    {
        if (!visited.Add(nums[i]))
        {
            continue;
        }

        var tmp = nums[idx];
        nums[idx] = nums[i];
        nums[i] = tmp;

        recur_permuteUnique(res, idx + 1, nums);

        tmp = nums[idx];
        nums[idx] = nums[i];
        nums[i] = tmp;
    }
}
}