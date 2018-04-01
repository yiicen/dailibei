/*
ou are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

extern struct ListNode * AddTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int carry_num = 0;
    int first = 1;
    struct ListNode *res = NULL;
    struct ListNode *p = NULL;
    struct ListNode *prev = p;

    while (l1 != NULL || l2 != NULL || carry_num != 0) {
        int sum = 0;
        int last_carry = carry_num;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        if (sum >= 10) {
            sum -= 10;
            carry_num = 1;
        } else {
            carry_num = 0;
        }

        p = malloc(sizeof(struct ListNode));
        if (first) {
            res = p;
            first = 0;
        }
        p->val = sum + last_carry;
        if (p->val >= 10) {
            p->val -= 10;
            carry_num = 1;
        }
        p->next = NULL;
        if (prev != NULL) {
            prev->next = p;
        }
        prev = p;
    }

    return res;
}

