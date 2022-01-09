//
// Created by ZhiWei Tan on 9/17/21.
//

#ifndef LEETCODE_PLAYGROUD_H
#define LEETCODE_PLAYGROUD_H

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <vector>
#include <numeric>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


string integerVectorToString(vector<int> list, int length = -1);
vector<int> stringToIntegerVector(string input);
ListNode* stringToListNode(string input);
string listNodeToString(ListNode* node);
void prettyPrintLinkedList(ListNode* node);

#endif //LEETCODE_PLAYGROUD_H
