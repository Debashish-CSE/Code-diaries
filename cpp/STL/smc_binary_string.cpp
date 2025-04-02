#include <iostream>
#include <string>

using namespace std;

int main() {
    string binaryString1, binaryString2;

    // Input two binary strings
    cout << "Enter the first binary string: ";
    cin >> binaryString1;
    cout << "Enter the second binary string: ";
    cin >> binaryString2;

    // Check if the lengths of both strings are equal
    if (binaryString1.length() != binaryString2.length()) {
        cout << "Error: Binary strings must have equal lengths." << endl;
        return 1;
    }

    int f01 = 0, f10 = 0, f11 = 0, f00 = 0;

    // Iterate through both strings
    for (size_t i = 0; i < binaryString1.length(); ++i){

        if (binaryString1[i] == '0' && binaryString2[i] == '1') {
            f01++;
        } 
        else if (binaryString1[i] == '1' && binaryString2[i] == '0') {
            f10++;
        } 
        else if (binaryString1[i] == '1' && binaryString2[i] == '1') {
            f11++;
        } 
        else if (binaryString1[i] == '0' && binaryString2[i] == '0') {
            f00++;
        }
    }

    // Calculate SMC using the formula: SMC = (f11 + f00) / (f01 + f10 + f11 + f00)
    double numerator = (f11 + f00);
    double denominator = (f01 + f10 + f11 + f00);
    double smc = numerator / denominator;

    cout << "Simple Matching Coefficient (SMC): " << smc << endl;

    return 0;
}
