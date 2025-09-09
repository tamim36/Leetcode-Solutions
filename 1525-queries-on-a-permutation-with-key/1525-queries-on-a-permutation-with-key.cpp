class Solution {
public:
    int processEachQuery(ListNode* head, int query) {
    ListNode* cur = head;
    int idx = 0;

    while (cur && cur->next) {
        if (cur->next->val == query) {
            ListNode* tempNode = cur->next;
            cur->next = cur->next->next;
            tempNode->next = head->next;
            head->next = tempNode;
            break;
        }

        idx++;
        cur = cur->next;
    }

    return idx;
}

vector<int> processQueries(vector<int>& queries, int m) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;

    for (int i = 1; i <= m; i++) {
        ListNode* newNode = new ListNode(i);
        cur->next = newNode;
        cur = cur->next;
    }

    vector<int> ans;

    for (auto query : queries) {
        ans.push_back(processEachQuery(head, query));
    }

    return ans;
}
};