//
// Created by ZhiWei Tan on 1/2/22.
//

#include "playgroud.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "#";
        }

        // 前序遍历
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss;
        char delim = ',';
        ss.str(data);
        string item;
        queue<string> q;
        while (getline(ss, item, delim)) {
            q.push(item);
        }

        return dfs(q);
    }

    TreeNode* dfs(queue<string> &q)
    {
        if (q.empty()) {
            return nullptr;
        }

        string item = q.front();
        q.pop();

        if (item == "#") {
            return nullptr;
        }

        TreeNode *node = new TreeNode(stoi(item));
        node->left = dfs(q);
        node->right = dfs(q);

        return node;
    }
};

