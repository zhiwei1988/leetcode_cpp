//
// Created by ZhiWei Tan on 12/18/21.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto *leftEnd = findMidListNode(head);
        auto *rightStart = reverseList(leftEnd->next);
        auto p1 = head;
        auto p2 = rightStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        return result;
    }

private:
    // 通过快慢指针查找链表的中间节点
    ListNode *findMidListNode(ListNode *head)
    {
        auto *fast = head;
        auto *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    /**
     * 翻转链表
     * @param head
     * @return 翻转后的链表的首节点
     */
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        while (head != nullptr) {
            auto *next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }

        return pre;
    }
};

