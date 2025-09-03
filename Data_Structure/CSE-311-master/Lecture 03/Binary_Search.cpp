#include <bits/stdc++.h>
using namespace std;
int main()
{
    int DATA[] = {3, 5, 7, 9, 12, 14, 18, 21, 23, 27, 32, 36, 38, 42, 45, 47, 50};
    int LB = 0, UB = 16, MID, ITEM = 1, LOC, BEG, END;
    BEG = LB;
    END = UB;
    MID = (BEG + END) / 2;
    while (BEG <= END && DATA[MID] != ITEM)
    {
        if (ITEM < DATA[MID])
        {
            END = MID - 1;
        }
        else
        {
            BEG = MID + 1;
        }
        MID = (BEG + END) / 2;
    }
    if (DATA[MID] == ITEM)
    {
        LOC = MID;
        cout << "Found at: " << LOC << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}
