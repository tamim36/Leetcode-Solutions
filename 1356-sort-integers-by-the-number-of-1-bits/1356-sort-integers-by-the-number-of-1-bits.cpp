class Solution {
public:


struct BitComparator {
    bool operator()(int a1, int a2) const {
        int n1 = a1, n2 = a2;
        int bit1 = 0;
    while (n1) {
        n1 = n1 & n1 - 1;
        bit1++;
    }
        
        int bit2 = 0;
    while (n2) {
        n2 = n2 & n2 - 1;
        bit2++;
    }
        
        return bit1 == bit2 ? a1 < a2 : bit1 < bit2;
    }
};

// 1356
vector<int> sortByBits(vector<int>& arr) {
    sort(begin(arr), end(arr), BitComparator());
    return arr;
}
};