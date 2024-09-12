#ifndef INC_206_REVERSE_LINKED_LIST_H
#define INC_206_REVERSE_LINKED_LIST_H

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

/*#include "LeetCode/206. Reverse Linked List.h"

int main() {
    Solution sol;

    // Case 1: [1, 2, 3, 4, 5]
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    cout << "Original list: ";
    printList(head1);
    ListNode* reversedHead1 = sol.reverseList(head1);
    cout << "Reversed list: ";
    printList(reversedHead1);

    return 0;
}*/


#endif //INC_206_REVERSE_LINKED_LIST_H
