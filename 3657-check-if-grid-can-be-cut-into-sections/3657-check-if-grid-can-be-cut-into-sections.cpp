class Solution {
public:
    bool checkValidCuts(vector<pair<int, int>>& cuts) {
        int lastEnd = cuts[0].second;
        int gapCount = 0;

        for (auto cut : cuts) {
            if (cut.first >= lastEnd) {
                ++gapCount;
            }

            lastEnd = max(lastEnd, cut.second);
        }

        return gapCount >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xCuts, yCuts;

        for (auto rectangle : rectangles) {
            xCuts.push_back(make_pair(rectangle[0], rectangle[2]));
            yCuts.push_back(make_pair(rectangle[1], rectangle[3]));
        }

        sort(xCuts.begin(), xCuts.end());
        sort(yCuts.begin(), yCuts.end());

        return checkValidCuts(xCuts) || checkValidCuts(yCuts);
    }
};