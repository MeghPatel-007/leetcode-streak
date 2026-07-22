#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Segment Tree : Sum query - II
    void buildSegmentTree(int l, int r, vector<int> &segTree, int arr[], int i)
    {
        if (l == r)
        {
            segTree[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(l, mid, segTree, arr, 2 * i + 1);
        buildSegmentTree(mid + 1, r, segTree, arr, 2 * i + 2);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
    int query(int start, int end, int l, int r, vector<int> &segTree, int i)
    {
        if (l > end || r < start)
            return 0;
        if (l >= start && r <= end)
            return segTree[i];
        int mid = l + (r - l) / 2;
        return query(start, end, l, mid, segTree, 2 * i + 1) + query(start, end, mid + 1, r, segTree, 2 * i + 2);
    }
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        vector<int> segTree(4 * n);
        buildSegmentTree(0, n - 1, segTree, arr, 0);
        vector<int> ans;
        for (int i = 0; i < 2 * q; i += 2)
        {
            int sum = query(queries[i] - 1, queries[i + 1] - 1, 0, n - 1, segTree, 0);
            ans.push_back(sum);
        }
        return ans;
    }
};
