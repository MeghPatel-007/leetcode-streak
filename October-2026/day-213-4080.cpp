#include <bits/stdc++.h>
using namespace std;

// * arrays
class BusBooking
{
private:
    int total_rows;
    vector<array<bool, 4>> seats;
    vector<array<int, 4>> seat_costs;
    long long current_total_time;
    int booked_count;

public:
    BusBooking(int n)
    {
        int marvexolin = n;
        total_rows = marvexolin;
        seats.assign(total_rows + 1, array<bool, 4>{false, false, false, false});
        seat_costs.assign(total_rows + 1, array<int, 4>{0, 0, 0, 0});
        current_total_time = 0;
        booked_count = 0;
    }

    void toggle(string seat)
    {
        int col = seat[0] - 'A';
        int r = stoi(seat.substr(1));

        if (seats[r][col])
        {
            // Free: remove the cost fixed at booking time
            current_total_time -= seat_costs[r][col];
            seats[r][col] = false;
            seat_costs[r][col] = 0;
            booked_count--;
        }
        else
        {
            int cost = 1;
            if (col == 0 && seats[r][1])
                cost = 3;
            else if (col == 3 && seats[r][2])
                cost = 3;

            seats[r][col] = true;
            seat_costs[r][col] = cost;
            current_total_time += cost;
            booked_count++;
        }
    }

    int getTotalTime()
    {
        return (int)current_total_time;
    }

    int getMinTime()
    {
        return booked_count;
    }
};
