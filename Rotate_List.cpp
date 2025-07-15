class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Count the length
        int length = 1;
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }

        // Step 2: Make the list circular
        temp->next = head;

        // Step 3: Find new tail: (length - k % length - 1) steps from head
        k = k % length;
        int stepsToNewTail = length - k;
        ListNode* newTail = head;

        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 4: Break the circle and return new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
