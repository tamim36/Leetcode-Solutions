class Solution {
public:
    void pancakeSortFlippedFirstKItems(vector<int>& arr, int k) {
        k = k - 1;
        for (int i = 0; i < k; i++, k--) {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }

    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;

        for (int i = arr.size() - 1; i >= 0; i--) {
            int maxValIdx = i;

            for (int j = i - 1; j >= 0; j--)
                maxValIdx = arr[j] > arr[maxValIdx] ? j : maxValIdx;

            if (maxValIdx == i)
                continue;

            if (maxValIdx + 1 > 1) {
                ans.push_back(maxValIdx + 1);
                pancakeSortFlippedFirstKItems(arr, maxValIdx + 1);
            }

            ans.push_back(i + 1);
            pancakeSortFlippedFirstKItems(arr, i + 1);
        }

        return ans;
    }
};