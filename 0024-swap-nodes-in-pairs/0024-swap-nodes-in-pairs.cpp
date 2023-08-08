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
    ListNode* swapTwoNodes(ListNode* node1, ListNode* node2) {
    node1->next = node1->next->next;
    node2->next = node1;
    return node2;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* newHead = new ListNode(0);
    newHead->next = head;

    ListNode* cur = newHead;

    while (cur && cur->next && cur->next->next)
    {
        cur->next = swapTwoNodes(cur->next, cur->next->next);
        cur = cur->next->next;
    }


    return newHead->next;
}
};