public class Solution {
    public long MinimalKSum(int[] nums, int k) {
        Array.Sort(nums);

            long sumKnum = 0, ansSum = 0;
            int limit = k;
            for (int i = 0; i < nums.Length && nums[i] <= limit; i++)
            {
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;

                sumKnum += nums[i];
                limit++;
            }

            ansSum = ((long)limit * ((long)limit + 1)) / 2;
            return ansSum - sumKnum;
    }
}