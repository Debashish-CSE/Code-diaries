// GitHub Copilot Generated

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char Character;
    int Frequency;
    Node *Left;
    Node *Right;

    Node(char Character, int Frequency)
    {
        this->Character = Character;
        this->Frequency = Frequency;
        this->Left = NULL;
        this->Right = NULL;
    }
};

// Comparator function for the priority queue
bool Compare(Node *a, Node *b)
{
    return a->Frequency > b->Frequency; // Min-heap based on frequency
}

// Function to build the Huffman Tree
Node *BuildHuffmanTree(const unordered_map<char, int> &freqMap)
{
    // Priority queue with a custom comparator function
    auto cmp = [](Node *a, Node *b)
    { return Compare(a, b); };
    priority_queue<Node *, vector<Node *>, decltype(cmp)> pq(cmp);

    // Create a leaf node for each character and push it into the priority queue
    for (auto &entry : freqMap)
    {
        pq.push(new Node(entry.first, entry.second));
    }

    // Build the Huffman Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // Create a new internal node with the sum of the frequencies
        Node *newNode = new Node('\0', left->Frequency + right->Frequency);
        newNode->Left = left;
        newNode->Right = right;

        pq.push(newNode);
    }

    return pq.top(); // Root of the Huffman Tree
}

// Function to generate Huffman Codes by traversing the tree
void GenerateHuffmanCodes(Node *root, string code, unordered_map<char, string> &huffmanCodes)
{
    if (!root)
    {
        return;
    }

    // If it's a leaf node, store the character and its code
    if (!root->Left && !root->Right)
    {
        huffmanCodes[root->Character] = code;
    }

    GenerateHuffmanCodes(root->Left, code + "0", huffmanCodes);
    GenerateHuffmanCodes(root->Right, code + "1", huffmanCodes);
}

// Function to print the Huffman Codes
void PrintHuffmanCodes(const unordered_map<char, string> &huffmanCodes)
{
    cout << "Huffman Codes:\n";
    for (auto &entry : huffmanCodes)
    {
        cout << entry.first << ": " << entry.second << endl;
    }
}

// Main function to test Huffman Coding
int main()
{
    // Input: characters and their frequencies
    unordered_map<char, int> freqMap = {
        {'d', 1}, {'e', 1}, {'h', 1}, {'r', 1}, {'w', 1}, {'o', 2}, {'l', 3}};

    // Build the Huffman Tree
    Node *root = BuildHuffmanTree(freqMap);

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    GenerateHuffmanCodes(root, "", huffmanCodes);

    // Print the Huffman Codes
    PrintHuffmanCodes(huffmanCodes);

    return 0;
}