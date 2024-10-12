class Solution {
public:
   unordered_map<int, unordered_map<int, int>> memo;

    int findTargetSumWays(vector<int>& nums, int target, int curSum, int n) {
        // Base case: when n is 0, check if the current sum is equal to the target
        if (n == 0) 
            return curSum == target ? 1 : 0;
        
        // Check if the result for the current subproblem (n, curSum) is already memoized
        if (memo[n].find(curSum) != memo[n].end())
            return memo[n][curSum];

        // Recursively calculate the number of ways by adding and subtracting the current element
        int add = findTargetSumWays(nums, target, curSum + nums[n - 1], n - 1);
        int subtract = findTargetSumWays(nums, target, curSum - nums[n - 1], n - 1);

        // Store the result in the memo table before returning
        memo[n][curSum] = add + subtract;

        return memo[n][curSum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return findTargetSumWays(nums, target, 0, nums.size());
    }
};