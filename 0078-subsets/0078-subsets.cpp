class Solution {
public:
    void backtrack_subset(vector<vector<int>>& ansList, vector<int>& tmpList, vector<int>& nums, int start) {
    ansList.push_back(tmpList);

    for (int i = start; i < nums.size(); i++) {
        tmpList.push_back(nums[i]);

        backtrack_subset(ansList, tmpList, nums, i + 1);

        tmpList.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ansList;
    //sort(nums.begin(), nums.end());
    vector<int> tmpList;
     backtrack_subset(ansList, tmpList, nums, 0);
    return ansList;
}
};