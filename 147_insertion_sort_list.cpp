
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode dummy(0);
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* nextNode = curr->next;
            ListNode* prev = &dummy;

            while (prev->next != nullptr &&
                   prev->next->val <= curr->val) {

                prev = prev->next;
            }

            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy.next;
    }
};

int main() {

    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution obj;

    head = obj.insertionSortList(head);

    cout << "Sorted Linked List: ";

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;

    return 0;
}
