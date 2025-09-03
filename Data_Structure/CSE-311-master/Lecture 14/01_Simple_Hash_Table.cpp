#include <bits/stdc++.h>
using namespace std;

class HashTable
{
    static const int table_size = 10;             // size of the hash table
    list<pair<string, string>> table[table_size]; // array of linked lists

    int hashFunction(string key)
    {
        int hash = 0;
        for (char ch : key)
        {
            hash += ch;
        }
        return hash % table_size; // return index based on key
    }

public:
    void insert(string key, string value)
    {
        int index = hashFunction(key);
        table[index].push_back(make_pair(key, value)); // store key-value pair
    }

    string get(string key)
    {
        int index = hashFunction(key);
        for (auto &pair : table[index])
        {
            if (pair.first == key)
            {
                return pair.second; // return the value if key matches
            }
        }
        return "Not Found"; // return error if key not found
    }
};

int main()
{
    HashTable ht;
    ht.insert("jsmith", "John Smith");
    ht.insert("jdoe", "Jane Doe");

    cout << "Value for key 'jsmith': " << ht.get("jsmith") << endl;
    cout << "Value for key 'jdoe': " << ht.get("jdoe") << endl;
    return 0;
}
