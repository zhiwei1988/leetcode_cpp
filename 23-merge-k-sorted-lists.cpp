//
// Created by ZhiWei Tan on 1/9/22.
//

#include "playgroud.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        return partion(lists, 0, lists.size() - 1);
    }

    ListNode* partion(vector<ListNode*>& list, int left, int right) {
        if (left >= right) {
            return list[left];
        }

        int mid = left + (right - left) / 2;
        auto leftSide = partion(list, left, mid);
        auto rightSide = partion(list, mid + 1, right);

        return merge(leftSide, rightSide);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }

        if (l2 == nullptr) {
            return l1;
        }

        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};

int main()
{
    string list1 = "{1,4,5}";
    string list2 = "{1,3,4}";
    string list3 = "{2,6}";
    vector<ListNode*> lists;
    lists.push_back(stringToListNode(list1));
    lists.push_back(stringToListNode(list2));
    lists.push_back(stringToListNode(list3));
    auto ret = Solution().mergeKLists(lists);
    prettyPrintLinkedList(ret);
    return 0;
}

