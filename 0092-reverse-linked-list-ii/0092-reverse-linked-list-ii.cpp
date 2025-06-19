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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        // Move `prev` to the node just before `left`
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // `start` points to the first node to be reversed
        ListNode* start = prev->next;
        // `then` points to the node that will be moved
        ListNode* then = start->next;

        // Reverse the sublist from left to right
        for (int i = 0; i < right - left; ++i) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }

        return dummy.next;
    }
};
