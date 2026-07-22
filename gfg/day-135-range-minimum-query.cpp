#include <bits/stdc++.h>
using namespace std;

/* The functions which
builds the segment tree */
void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[])
{
    if (l == r)
    {
        segmentTree[i] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}
int *constructST(int arr[], int n)
{
    // Your code here
    int *segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

int query(int start, int end, int i, int l, int r, int segTree[])
{
    if (l > end || r < start)
        return INT_MAX;
    if (l >= start && r <= end)
        return segTree[i];
    int mid = l + (r - l) / 2;
    return min(query(start, end, 2 * i + 1, l, mid, segTree),
               query(start, end, 2 * i + 2, mid + 1, r, segTree));
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b)
{
    return query(a, b, 0, 0, n - 1, st);
    // Your code here
}
