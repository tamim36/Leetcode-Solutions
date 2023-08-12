class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int m = 0, g = 0, p = 0;

    for (int i = garbage.size() - 1; i >= 0; i--) {
        for (auto c : garbage[i]) {
            switch (c)
            {
                case 'M':
                    m++;
                    break;
                case 'P':
                    p++;
                    break;
                case 'G':
                    g++;
                    break;
            }
        }

        m += m > 0 && i > 0 ? travel[i - 1] : 0;
        p += p > 0 && i > 0 ? travel[i - 1] : 0;
        g += g > 0 && i > 0 ? travel[i - 1] : 0;
    }

    return m + p + g;
    }
};