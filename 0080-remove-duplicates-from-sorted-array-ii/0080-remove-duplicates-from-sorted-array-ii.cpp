class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       bool duplicateAllowed = true;
       int left = 1, right = 1;

        for (; right < nums.size(); right++){
            nums[left] = nums[right];
            if (nums[left] == nums[left - 1] && duplicateAllowed)
                duplicateAllowed = false, left++;
            else if (nums[left] != nums[left - 1])
                duplicateAllowed = true, left++;
        }

        return left;
    }
};