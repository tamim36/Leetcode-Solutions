class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;

int a = nums[0], b = INT32_MAX;

for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > b)
        return true;
    else if (nums[i] > a && nums[i] < b)
        b = nums[i];
    else if (nums[i] < a)
        a = nums[i];
}

return false;
    }
};