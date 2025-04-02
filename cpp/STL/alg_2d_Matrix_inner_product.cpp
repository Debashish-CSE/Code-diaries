#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to compute dot product of two matrices
int dotProduct(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
    vector<int> flattened1, flattened2;

    // Flatten both matrices into vectors
    for (const auto& row : matrix1) {
        flattened1.insert(flattened1.end(), row.begin(), row.end());
    }

    for (const auto& row : matrix2) {
        flattened2.insert(flattened2.end(), row.begin(), row.end());
    }

    // Compute the dot product using inner_product
    return inner_product(flattened1.begin(), flattened1.end(), flattened2.begin(), 0);
}

int main() {
    // Define two matrices
    vector<vector<int>> matrix1 = {{1, 2}, {3, 4}};
    vector<vector<int>> matrix2 = {{5, 6}, {7, 8}};

    // Compute the dot product
    int result = dotProduct(matrix1, matrix2);

    // Print the result
    cout << "Dot Product of the two matrices: " << result << endl;

    return 0;
}
