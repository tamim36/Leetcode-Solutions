class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int validIdx = 0;
int allowedOneDuplicate = 1;

for (int i = 1; i < nums.size(); i++) {
    if (nums[i - 1] != nums[i])
        validIdx++, allowedOneDuplicate = 1;
    else if (allowedOneDuplicate)
        validIdx++, allowedOneDuplicate = 0;

    nums[validIdx] = nums[i];
}

return validIdx + 1;
    }
};