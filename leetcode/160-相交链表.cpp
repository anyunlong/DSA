/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    
    struct ListNode *cursorA = headA;
    struct ListNode *cursorB = headB;
    // 1次
    while (true) {
        if (cursorA == NULL && cursorB == NULL) {
            cursorA = headA;
            cursorB = headB;
            break;
        }
        if (cursorB == NULL) {
            cursorB = headA;
            cursorA = cursorA->next;
            break;
        }
        if (cursorA == NULL) {
            cursorA = headB;
            cursorB = cursorB->next;
            break;
        }
        cursorA = cursorA->next;
        cursorB = cursorB->next;
    }
    // 2次
    while (true) {
        if (cursorA == NULL && cursorB == NULL) {
            cursorA = headA;
            cursorB = headB;
            break;
        }
        if (cursorB == NULL) {
            cursorB = headA;
            cursorA = cursorA->next;
            break;
        }
        if (cursorA == NULL) {
            cursorA = headB;
            cursorB = cursorB->next;
            break;
        }
        cursorA = cursorA->next;
        cursorB = cursorB->next;
    }
    while (true) {
        if (cursorA == cursorB) {
            if (cursorA == NULL) {
                return NULL;
            } else {
                return cursorA;
            }
            break;
        }
        cursorA = cursorA->next;
        cursorB = cursorB->next;
    }
    
    return NULL;
}
