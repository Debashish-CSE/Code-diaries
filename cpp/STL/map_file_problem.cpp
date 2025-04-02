#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Original data map
    map<int, double> m = { {100,348.17},{300,27.19},{500,0.00},{700,-14.22} };

    // Write original data to "oldmust.txt"
    ofstream oldFile("oldmust.txt");
    for(auto i = m.begin(); i != m.end(); ++i) {
        oldFile << i->first << " " << i->second << endl;
    }
    oldFile.close();

    // Data from "trans.txt"
    map<int, double> m2 = { {100,27.14},{300,146.0},{400,100.56},{700,82.31},{900,82.17} };

    // Open "newmust.txt" for writing
    ofstream newFile("newmust.txt");

    // Open "log.txt" for writing unmatched transactions
    ofstream logFile("log.txt");

    // Iterate over each line in "trans.txt" and update if necessary 
    for(auto it = m2.begin(); it != m2.end(); ++it) {
        int key = it->first;
        double value = it->second;

        // Check if the key exists in m
        auto it_m = m.find(key);
        if (it_m != m.end()) {
            // Add the value from m2 to the corresponding value in m
            m[key] += value;
        } else {
            // Write unmatched transaction to log file
            logFile << "Unmatched transaction for A/C no: " << key << endl;
        }
    }

    // Write the updated data to "newmust.txt"
    for(auto i = m.begin(); i != m.end(); ++i) {
        newFile << i->first << " " << i->second << endl;
    }
    
    // Close files
    newFile.close();
    logFile.close();

    cout << "Processing complete. Check newmust.txt for results and log.txt for unmatched transactions." << endl;

    return 0;
}
