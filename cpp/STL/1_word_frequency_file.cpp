#include <bits/stdc++.h>
using namespace std;

void countWordFrequency(const string& filename, const string& filename2) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error opening file.\n";
        return;
    }

    map<string, int> wordCount;
    string line;

    // Count word frequency
    while (getline(inFile, line)) {
        stringstream ss(line);
        string word;

        while (ss >> word) {
            wordCount[word]++;
        }
    }
    inFile.close();

    cout << "Word frequencies:\n";
    for (const auto& entry : wordCount) {
        cout << "  " << entry.first << ": " << entry.second << "\n";
    }
    cout << endl;

    // Synonym processing
    ifstream inFile2(filename2);
    if (!inFile2.is_open()) {
        cout << "Error opening synonym file.\n";
        return;
    }

    map<int, vector<string>> lineMap;
    int synLineNumber = 1;

    while (getline(inFile2, line)) {
        vector<string> words;
        stringstream ss(line);
        string word;

        while (getline(ss, word, ',')) {
            words.push_back(word);
        }

        lineMap[synLineNumber] = words;
        ++synLineNumber;
    }
    inFile2.close();

    cout << "Synonym Group Frequencies:\n";
    for (const auto& entry : lineMap) {
        int totalFreq = 0;
        int wordMatchCount = 0;
        cout << "Group " << entry.first << ": ";

        for (const string& w : entry.second) {
            if (wordCount.find(w) != wordCount.end()) {
                cout << w << "(" << wordCount[w] << ") ";
                totalFreq += wordCount[w];
                wordMatchCount++;
            }
        }

        cout << "=> Total Frequency: " << totalFreq 
             << ", Words Found: " << wordMatchCount << "\n";
    }
    cout << endl;
}
    
int main() {
    string filename = "input.txt";
    string filename2 = "synonyms.txt";

    countWordFrequency(filename, filename2);

    return 0;
}


