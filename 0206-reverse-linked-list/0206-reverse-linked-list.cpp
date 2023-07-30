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
    ListNode* recursive_reverseList(ListNode* head, ListNode* newHead) {
    if (head == NULL)
        return newHead;
    ListNode* temp = head->next;
    head->next = newHead;
    newHead = head;
    return recursive_reverseList(temp, newHead);
}

ListNode* reverseList(ListNode* head) {
    ListNode* newHead = NULL;
    return recursive_reverseList(head, newHead);
}
};