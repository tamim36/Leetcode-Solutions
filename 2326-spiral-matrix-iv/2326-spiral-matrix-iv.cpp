/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        queue<pair<int, int>> dir;
dir.push({0, 1});
dir.push({1, 0});
dir.push({0, -1});
dir.push({-1, 0});

int r = 0, c = 0;
vector<vector<int>> ans(m, vector<int>(n, -1));
for (int i = 0; i < m * n; i++) {
    if (head != NULL) {
        //cout << r << " " << c << endl;
        if (r == 2 && c == 0) {
            cout << "" << endl;
        }
        ans[r][c] = head->val;
        head = head->next;
    }
    else {
        return ans;
    }

    int curX = dir.front().first;
    int curY = dir.front().second;
    if (r + curX >= m || c + curY >= n || r + curX < 0 || c + curY < 0 || ans[r + curX][c + curY] != -1) {
        dir.pop();
        dir.push({ curX, curY });
        curX = dir.front().first;
        curY = dir.front().second;
    }

    r += curX;
    c += curY;
}

return ans;
    }
};