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
    vector<int> v;
    void traversal(TreeNode *root)
    {
        if (root != NULL)
        {
            traversal(root->left);
            v.push_back(root->val);
            traversal(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        traversal(root);
        return v;
    }
};