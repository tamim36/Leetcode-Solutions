class Solution {
public:
    int fpFindCircleNum(vector<int>& parent, int x) {
    return parent[x] == x ? x : fpFindCircleNum(parent, parent[x]);
}

int findCircleNum(vector<vector<int>>& isCon) {
    int n = isCon.size();
    vector<int> parent(n, 0);

    for (int i = 0; i < n; i++)
        parent[i] = i;
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++){
            if (isCon[r][c]) {
                int x = fpFindCircleNum(parent, r);
                int y = fpFindCircleNum(parent, c);
                if (x != y) parent[y] = x;
            }
        }
    }
    
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(fpFindCircleNum(parent ,i));
        

    return st.size();
}
};