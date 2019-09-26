/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// // 递归超出时间限制了，我靠
// struct ListNode* reverseList(struct ListNode* head) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     struct ListNode *newHead = reverseList(head->next);
//     head->next->next = head;
//     head->next == NULL;
//     return newHead;
// }

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode *lastNode = NULL;
    while (head) {
        struct ListNode *nextNode = head->next;
        head->next = lastNode;
        lastNode = head;
        head = nextNode;
    }
    return lastNode;
}
