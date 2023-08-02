class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

    vector<int> pre(n, 0), post(n, 0);
    int oneCnt = 0;

    for (int i = 1; i < n; i++) {
        if (boxes[i - 1] == '1')
            ++oneCnt;

        pre[i] = pre[i - 1] + oneCnt;
    }

    oneCnt = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (boxes[i + 1] == '1')
            ++oneCnt;

        post[i] = post[i + 1] + oneCnt;
    }

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        ans[i] = pre[i] + post[i];
    }

    return ans;
    }
};