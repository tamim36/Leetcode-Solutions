class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int unqIdx = nums.size() - 1;

    for (int i = nums.size() - 1; i >= 0; i--){
        if (nums[i] == val) nums[i] = nums[unqIdx--];
    }

    return unqIdx + 1;
}
};