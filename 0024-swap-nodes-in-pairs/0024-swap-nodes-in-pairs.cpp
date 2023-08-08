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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(0);
    newHead->next = head;

    ListNode* cur = newHead;

    while (cur && cur->next && cur->next->next)
    {
        auto temp = cur->next; // 1

        cur->next = cur->next->next;
        temp->next = cur->next->next;
        auto temp2 = cur->next;
        temp2->next = temp;
        cur->next = temp2;
        cur = cur->next->next;
    }


    return newHead->next;
    }
};