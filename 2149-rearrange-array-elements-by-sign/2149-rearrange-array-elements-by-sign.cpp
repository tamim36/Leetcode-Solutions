class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v(nums.size());

    for (int i = 0, ev = 0, od = 1; i < nums.size(); i++) {
        if (nums[i] >= 0) {
            v[ev] = nums[i];
            ev += 2;
        }
        else {
            v[od] = nums[i];
            od += 2;
        }
    }
    return v;
    }
};