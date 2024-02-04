class Solution {
public:
    int lastRemaining(int n) {
        bool isHeadRemove = true;
        int head = 1;
        int step = 1;

        int items = n;

        while (items > 1) {
            if (isHeadRemove || items % 2 == 1) {
                head = head + step;
            }

            step *= 2;
            isHeadRemove = !isHeadRemove;
            items /= 2;
        }

        return head;
    }
};