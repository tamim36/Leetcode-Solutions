class Solution {
public:
    bool bsToFindElem(int num, vector<int>& arr) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == num)
            return true;
        else if (arr[mid] > num)
            right = mid;
        else
            left = mid + 1;
    }
    return false;
}

// 888
vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    vector<int> v(2);
    int aSum = 0, bSum = 0;
    for (auto num : aliceSizes) aSum += num;
    for (auto num : bobSizes) bSum += num;
    sort(bobSizes.begin(), bobSizes.end());

    //int dif = abs(aSum - bSum);
    // x + (dif/2) = y
    // 2y = bSum - aSum + x + x
    for (auto x : aliceSizes) {
        int y = (bSum - aSum + x + x) / 2;
        if (bsToFindElem(y, bobSizes) && (aSum - x + y) == (bSum - y + x)) {
            v[0] = x;
            v[1] = y;
            break;
        }
    }

    return v;
}
};