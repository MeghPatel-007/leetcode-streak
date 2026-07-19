#include <bits/stdc++.h>
using namespace std;

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
    int d = 0;
    int traversal_count(TreeNode *root)
    {
        if (root != nullptr)
        {
            int l = traversal_count(root->left);
            int r = traversal_count(root->right);
            if (root->val >= max(l, r))
                d++;
            return max({root->val, l, r});
        }
        return 0;
    }
    int countDominantNodes(TreeNode *root)
    {
        traversal_count(root);
        return d;
    }
};
