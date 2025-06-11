class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // Save next node
            curr->next = prev;               // Reverse the link
            prev = curr;                     // Move prev forward
            curr = nextTemp;                 // Move curr forward
        }

        return prev; // New head of the reversed list
    }
};
