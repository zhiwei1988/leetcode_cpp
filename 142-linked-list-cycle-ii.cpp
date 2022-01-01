//
// Created by ZhiWei Tan on 1/1/22.
//

#include "playgroud.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        auto fast = head;
        auto slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }

        if (fast == slow) { // 链表有环
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }

        return nullptr;
    }
};

int main()
{
    string line = "[3,2,0,-4]";
    auto head = stringToListNode(line);
    auto ret = Solution().detectCycle(head);
    string out = listNodeToString(ret);
    cout << "ans = " << out << endl;
    return 0;
}

