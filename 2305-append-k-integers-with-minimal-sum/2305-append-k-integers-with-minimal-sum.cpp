class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (k < nums[0])
            return ((long long)k * (k + 1)/2);

        long long curSum = nums[0];
        k -= (nums[0] - 1);

        int i = 1;
        long long lastNum = nums[0];
        for (; i < nums.size() && k > 0; i++) {
            if ((nums[i] - nums[i - 1] - 1) > k){
                lastNum += k;
                k = 0;
            }
            else if (nums[i] != nums[i - 1]) {
                k -= (nums[i] - nums[i - 1] - 1);
                if (k >= 0) {
                    curSum += (long long)nums[i];
                    lastNum = nums[i];
                }
            }
        }
        
        lastNum += k;
        long long a = 10;
        long long test = (a * (a + 1)/2);
        cout << "test: " << test << endl;
        long long totalSum = lastNum * (lastNum + 1) / 2;
        return totalSum - curSum;
    }
};