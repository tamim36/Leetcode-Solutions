class SmallestInfiniteSet {
    set<int> st;
public:
    SmallestInfiniteSet() {
        st.insert(1);
    }

    int popSmallest() {
        auto it = st.begin();
        int val = *it;

        if (st.size() == 1) {
            st.insert(val + 1);
        }
        
        st.erase(it);
        return val;
    }

    void addBack(int num) {
        if (*rbegin(st) > num)
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */