public class Solution {
    public int[] AnswerQueries(int[] nums, int[] queries)
{
    Array.Sort(nums);
    int[] answer = new int[queries.Length];

    for (int i = 1; i < nums.Length; i++)
    {
        nums[i] += nums[i - 1];
    }

    for (int i = 0; i < queries.Length; i++)
    {
        answer[i] = binarySearchAnswerQueries(nums, queries[i]);
    }

    return answer;
}

public int binarySearchAnswerQueries(int[] nums, int val)
{
    int left = 0, right = nums.Length;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (val < nums[mid])
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}
}