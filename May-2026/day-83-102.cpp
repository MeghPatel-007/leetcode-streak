#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> v;
    void traversal(TreeNode *root, int level)
    {
        if (root != NULL)
        {
            if (v.size() == level)
            {
                v.push_back({});
            }
            traversal(root->left, 1 + level);
            v[level].push_back(root->val);
            traversal(root->right, 1 + level);
        }
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        traversal(root, 0);
        return v;
    }
};
