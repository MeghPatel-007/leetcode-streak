#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool can(long long d, const vector<long long> &pos, int k, long long perimeter)
    {
        int n = pos.size();
        // We only need to test starting points in the first interval [pos[0], pos[0] + d]
        // because if a valid configuration exists, at least one point must be in here.
        for (int i = 0; i < n && pos[i] <= pos[0] + d; ++i)
        {
            int count = 1;
            long long last = pos[i];
            long long first = pos[i];

            int curr = i + 1;
            for (int j = 1; j < k; ++j)
            {
                // Find next point at least d away
                auto it = lower_bound(pos.begin() + curr, pos.end(), last + d);
                if (it == pos.end())
                {
                    count = -1; // Can't find k points
                    break;
                }
                last = *it;
                curr = distance(pos.begin(), it) + 1;
                count++;
            }

            // Crucial: The distance between the last point and the first point
            // (going around the perimeter) must also be >= d.
            if (count == k && (first + perimeter - last) >= d)
            {
                return true;
            }
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>> &points, int k)
    {
        vector<long long> pos;
        long long perimeter = 4LL * side;

        for (auto &p : points)
        {
            long long x = p[0], y = p[1];
            if (y == 0)
                pos.push_back(x); // Bottom edge
            else if (x == side)
                pos.push_back(side + y); // Right edge
            else if (y == side)
                pos.push_back(3LL * side - x); // Top edge
            else
                pos.push_back(4LL * side - y); // Left edge
        }

        sort(pos.begin(), pos.end());

        long long low = 1, high = side * 2; // Max Manhattan dist can't exceed 2*side
        long long ans = 0;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (can(mid, pos, k, perimeter))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};
