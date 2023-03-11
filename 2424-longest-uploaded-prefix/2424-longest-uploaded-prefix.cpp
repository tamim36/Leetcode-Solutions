class LUPrefix {
    unordered_set<int> st;
    int cur = 0;
public:
    LUPrefix(int n) {

    }

    void upload(int video) {
        st.insert(video);

        while (st.find(cur + 1) != st.end())
            st.erase(++cur);
    }

    int longest() {
        return cur;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */