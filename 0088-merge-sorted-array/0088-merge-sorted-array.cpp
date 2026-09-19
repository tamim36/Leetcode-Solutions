class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int mIdx = m - 1, nIdx = n - 1;

    for (int i = m + n - 1; i >= 0; i--){
        if (mIdx >= 0 && nIdx >= 0){
            if (nums1[mIdx] > nums2[nIdx]) nums1[i] = nums1[mIdx--];
            else nums1[i] = nums2[nIdx--]; 
        }
        else if (mIdx >= 0) nums1[i] = nums1[mIdx--];
        else nums1[i] = nums2[nIdx--]; 
    }
}
};