#include <bits/stdc++.h>
using namespace std;

const int EMPTY_SLOT = -1;

class DoubleHashTable
{
private:
    vector<int> table;
    int tableSize;
    int currentSize;

    int hash1(int key)
    {
        return key % tableSize;
    }

    int hash2(int key)
    {
        return 1 + (key % 5);
    }

public:
    DoubleHashTable(int size) : tableSize(size), currentSize(0)
    {
        if (size <= 0)
        {
            throw invalid_argument("Table size must be positive.");
        }
        table.assign(tableSize, EMPTY_SLOT);
    }

    void insert(int key)
    {
        if (currentSize == tableSize)
        {
            return;
        }

        int index = hash1(key);

        if (table[index] == EMPTY_SLOT)
        {
            table[index] = key;
            currentSize++;
            return;
        }

        int step = hash2(key);
        int i = 1;
        while (true)
        {
            int newIndex = (index + i * step) % tableSize;

            if (table[newIndex] == EMPTY_SLOT)
            {
                table[newIndex] = key;
                currentSize++;
                return;
            }

            i++;
            if (i >= tableSize)
            {
                return;
            }
        }
    }

    void displayTable()
    {
        for (int i = 0; i < tableSize; ++i)
        {
            cout << "Slot " << i << ": ";
            if (table[i] == EMPTY_SLOT)
            {
                cout << "[EMPTY]";
            }
            else
            {
                cout << table[i];
            }
            cout << endl;
        }
    }
};

int main()
{
    DoubleHashTable hashTable(7);

    int keys[] = {27, 43, 692, 72};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; ++i)
    {
        hashTable.insert(keys[i]);
    }

    hashTable.displayTable();

    return 0;
}