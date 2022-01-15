//
// Created by ZhiWei Tan on 1/2/22.
//

#include "playground.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        GainMax(root);
        return maxPath;
    }

private:
    int GainMax(TreeNode* node)
    {
        if (node == nullptr) {
            return 0;
        }

        // 如果某个子节点能贡献的值小于 0，则放弃该节点
        int leftGain = max(GainMax(node->left), 0);
        int rightGain = max(GainMax(node->right), 0);
        maxPath = max(maxPath, node->val + leftGain + rightGain);
        // 当前节点只能取左右节点中较大的值，贡献给他的父节点
        return node->val + max(leftGain, rightGain);
    }

    int32_t maxPath = INT_MIN;
};

