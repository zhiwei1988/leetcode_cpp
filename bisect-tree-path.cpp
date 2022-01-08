//
// Created by ZhiWei Tan on 1/7/22.
//

#include "playgroud.h"

class Solution {
public:
    struct TreeNode* DeserializeBinaryTree(vector<string> &data)
    {
        auto size = data.size();
        int index = 0;
        TreeNode *root = new TreeNode(stoi(data[index]));
        index++;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto num = q.size();
            for (auto i = 0; i < num; i++) {
                auto node = q.front();
                q.pop();
                if (index < size) {
                    if (data[index] != "#") {
                        node->left = new TreeNode(stoi(data[index]));
                        q.push(node->left);
                    }

                    index++;
                } else {
                    return root;
                }

                if (index < size) {
                    if (data[index] != "#") {
                        node->right = new TreeNode(stoi(data[index]));
                        q.push(node->right);
                    }

                    index++;
                } else {
                    return root;
                }
            }
        }

        return root;
    }

    int BisectTreePath(struct TreeNode *root)
    {
        m_path.push_back(root);
        VisitNode(root, 0, 0);
        m_path.pop_back();
        return m_result;
    }

    void VisitNode(struct TreeNode *node, int pathSum, int depth)
    {
        if (node == nullptr) {
            return;
        }

        pathSum += node->val;
        m_result += node->val;
        if ((node->left == nullptr) && (node->right == nullptr)) {
            for (int i = 0; i < depth; i ++) {
                if (m_tags.count(m_path[i]) != 0) {
                    continue;
                }

                if (m_preSum[i] == (pathSum - m_preSum[i + 1])) {
                    m_result -= (m_preSum[i + 1] - m_preSum[i]);
                    m_tags.insert(m_path[i]);
                }
            }

            return;
        }

        m_preSum[depth + 1] = m_preSum[depth] + node->val;

        m_path.push_back(node->left);
        VisitNode(node->left, pathSum, depth + 1);
        m_path.pop_back();

        m_path.push_back(node->right);
        VisitNode(node->right, pathSum, depth + 1);
        m_path.pop_back();
    }

private:
    unordered_set<TreeNode*> m_tags;
    vector<TreeNode*> m_path;
    int m_preSum[100] = {0};
    int m_result = 0;
};

int main()
{
    vector<string> data = {"7","6","5","3","#","4","#","11","#","1","3","2","#","#","16"};
    auto root = Solution().DeserializeBinaryTree(data);
    auto ret = Solution().BisectTreePath(root);
    return 0;
}


