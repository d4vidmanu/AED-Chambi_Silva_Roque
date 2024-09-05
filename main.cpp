#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = head->next;
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current && current->next) {
            ListNode* first = current;
            ListNode* second = current->next;

            first->next = second->next;
            second->next = first;

            if (prev) {
                prev->next = second;
            }

            prev = first;
            current = first->next;
        }

        return newHead;
    }
};

void printList(ListNode* node) {
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

ListNode* createList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    std::vector<int> listValues = {1, 2, 3, 4};
    ListNode* head = createList(listValues);

    printList(head);

    ListNode* swappedHead = solution.swapPairs(head);

    printList(swappedHead);

    return 0;
}