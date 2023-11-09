// https://leetcode.com/problems/seat-reservation-manager/description/?envType=daily-question&envId=2023-11-06

#include <iostream>
using namespace std;
#include <queue>

class SeatManager
{
    // Tables--
    int n;

    // Reservations--
    priority_queue<int, vector<int>, greater<int>> tables;

    // Smallest UnReserved Table--
    int minTable;

public:
    SeatManager(int n)
    {
        // N Tables.
        this->n = n;

        minTable = 0;
    }

    int reserve()
    {
        // Find Smallest Numbered Unreserved Table
        if (!tables.empty())
        {
            int table = tables.top();
            tables.pop();
            return table + 1;
        }
        return minTable++ + 1;
    }

    void unreserve(int seatNumber)
    {
        tables.push(seatNumber - 1);
    }
};

// Time Limit Exceeded--
/*
class SeatManager
{
    // Tables--
    int n;

    // Reservations--
    bool *tables;

    // Smallest UnReserved Table--
    int minTable;

public:
    SeatManager(int n)
    {
        // N Tables.
        this->n = n;

        // False --> Unreserve
        // True --> Reserve
        tables = new bool[n];

        // Initialise Reservation.
        for (int i = 0; i < n; i++)
        {
            tables[i] = false;
        }

        minTable = 0;
    }

    int reserve()
    {
        // Find Smallest Numbered Unreserved Table
        while (tables[minTable])
        {
            minTable++;
        }
        tables[minTable] = true;
        return minTable++ + 1;
    }

    void unreserve(int seatNumber)
    {
        // Unreserve Table
        tables[seatNumber - 1] = false;

        if (seatNumber - 1 < minTable)
        {
            minTable = seatNumber - 1;
        }
    }
};
*/

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */