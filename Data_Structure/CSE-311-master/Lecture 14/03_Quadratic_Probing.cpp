#include <iostream>
#include <vector>
#include <string> // Include the string header for to_string

using namespace std;

class HashTable
{
    static const int table_size = 7;
    vector<string> table;

    int hashFunction(int key)
    {
        return key % table_size;
    }

public:
    HashTable() : table(table_size, "") {}

    void insert(int key)
    {
        int initial_index = hashFunction(key);
        int i = 0;
        int index = initial_index; // Start with the initial hash index

        // Probe until an empty slot is found
        while (table[index] != "")
        {
            i++;
            // Calculate next index based on initial index and i^2
            index = (initial_index + (i * i)) % table_size;
            if (i >= table_size)
            {
                cerr << "Error: Could not insert key " << key << ". Table might be full or probing failed." << endl;
                return; // Exit if we've probed too many times
            }
        }
        // Insert the key (as a string) into the empty slot
        table[index] = to_string(key);
    }

    void display()
    {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < table_size; i++)
        {
            if (table[i] != "")
            {
                cout << "Index " << i << ": " << table[i] << endl;
            }
            else
            {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }
};

int main()
{
    HashTable ht;
    ht.insert(22);
    ht.insert(30);
    ht.insert(50);
    ht.display();

    return 0;
}