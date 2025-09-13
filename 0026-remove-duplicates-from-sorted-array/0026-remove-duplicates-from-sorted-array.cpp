class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqIdx = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != nums[i])
                uniqIdx++;

            nums[uniqIdx] = nums[i];
        }

        return uniqIdx + 1;
    }
};