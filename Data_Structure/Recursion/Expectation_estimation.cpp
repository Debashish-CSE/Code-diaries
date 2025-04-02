#include <iostream>
using namespace std;

// Recursive function to calculate the expected time
double expectedTime() {
    
    double northTime = 1.0;  // North: 1 minute to exit
    double eastTime = 3.0;   // East: 3 minutes wandering, then return
    double southTime = 10.0; // South: 10 minutes wandering, then return
    double westTime = 5.0;   // West: 5 minutes to exit

    // Return the total expectation formula directly
    return (1.0 / 4.0) * (northTime + westTime) + 
           (1.0 / 4.0) * (eastTime + expectedTime()) + 
           (1.0 / 4.0) * (southTime + expectedTime());
}

int main() {
    
    double result = expectedTime();

    cout << "The expected number of minutes: " << result << " minutes" << endl;

    return 0;
}

