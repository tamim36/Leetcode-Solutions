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
    int pairSum(ListNode* head) {
        if (!head) return 0;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* temp = NULL;
    ListNode* revHead = NULL;
    int sum = 0;

    while (fast) {
        fast = fast->next->next;

        temp = slow->next;
        slow->next = revHead;
        revHead = slow;
        slow = temp;
    }

    while (slow) {
        sum = max(sum, slow->val + revHead->val);
        slow = slow->next;
        revHead = revHead->next;
    }

    return sum;
    }
};