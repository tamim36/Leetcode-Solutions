public class Solution {
    public int MinOperations(int[] nums, int x) {
        int sz = nums.Length;
int rem = nums.Sum();
rem -= x;

if (rem == 0) return sz;
if (rem < 0) return -1;

IDictionary<int, int> map = new Dictionary<int, int>();
map.Add(0, -1);

int curSum = 0, res = int.MinValue;
for (int i = 0; i < sz; i++)
{
    curSum += nums[i];

    if (map.ContainsKey(curSum - rem))
        res = Math.Max(res, i - map[curSum - rem]);

    map.Add(curSum, i);
}

return res == int.MinValue ? -1 : sz - res;
    }
}