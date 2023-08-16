class CustomStack {
    vector<int> vec;
    int top = -1, sz = 0;
public:
    CustomStack(int maxSize) : vec(maxSize, -1) {
        sz = maxSize;
    }

    void push(int x) {
        if (top >= sz - 1)
            return;

        vec[++top] = x;
    }

    int pop() {
        if (top < 0)
            return -1;
        return vec[top--];
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, sz); i++) {
            vec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */