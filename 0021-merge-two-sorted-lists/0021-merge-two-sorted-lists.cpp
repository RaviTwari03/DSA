class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the head of the merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Traverse both lists and add the smaller node to the merged list
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach the remaining nodes of the list that is not yet finished
        if (list1 != nullptr) current->next = list1;
        if (list2 != nullptr) current->next = list2;

        // The merged list is next to the dummy node
        return dummy->next;
    }
};
