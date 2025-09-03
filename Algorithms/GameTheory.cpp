#include <iostream>
#include <vector>
using namespace std;

//payoff (Player A, Player B)
typedef pair<int, int> Payoff;

// dominant strategy for a player
int findDominantStrategy(const vector<vector<Payoff>>& matrix, int player) {
    int n = matrix.size();    // Rows - strategies of Player A
    int m = matrix[0].size(); // Columns - strategies of Player B

    int bestStrategy = -1;

    if (player == 0) { // Player A
        for (int i = 0; i < n; ++i) {
            bool isDominant = true;
            for (int k = 0; k < n; ++k) {
                if (i == k) continue;
                for (int j = 0; j < m; ++j) {
                    if (matrix[i][j].first < matrix[k][j].first) {
                        isDominant = false;
                        break;
                    }
                }
                if (!isDominant) break;
            }
            if (isDominant) return i;
        }
    }
    else { // Player B
        for (int j = 0; j < m; ++j) {
            bool isDominant = true;
            for (int k = 0; k < m; ++k) {
                if (j == k) continue;
                for (int i = 0; i < n; ++i) {
                    if (matrix[i][j].second < matrix[i][k].second) {
                        isDominant = false;
                        break;
                    }
                }
                if (!isDominant) break;
            }
            if (isDominant) return j;
        }
    }
    return -1;
}

//Nash Equilibria
vector<pair<int, int>> findNashEquilibria(const vector<vector<Payoff>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<pair<int, int>> equilibria;

    for (int i = 0; i < n; ++i) {       // Player A's strategy
        for (int j = 0; j < m; ++j) {   // Player B's strategy
            int payoffA = matrix[i][j].first;
            int payoffB = matrix[i][j].second;

            bool isBestForA = true;
            bool isBestForB = true;

            // Check if A's strategy is best given B's strategy j
            for (int k = 0; k < n; ++k) {
                if (matrix[k][j].first > payoffA) {
                    isBestForA = false;
                    break;
                }
            }

            // Check if B's strategy is best given A's strategy i
            for (int k = 0; k < m; ++k) {
                if (matrix[i][k].second > payoffB) {
                    isBestForB = false;
                    break;
                }
            }

            if (isBestForA && isBestForB) {
                equilibria.push_back({i, j});
            }
        }
    }

    return equilibria;
}

int main() {
    // Player A: Rows, Player B: Columns
    vector<vector<Payoff>> matrix = {
        { {2,2}, {0,3} },
        { {3,0}, {1,1} }
    };

    cout << "Payoff Matrix (Player A, Player B):\n";
    for (const auto& row : matrix) {
        for (const auto& p : row)
            cout << "(" << p.first << "," << p.second << ") ";
        cout << endl;
    }

    int domA = findDominantStrategy(matrix, 0);
    int domB = findDominantStrategy(matrix, 1);

    cout << "\nDominant Strategy:\n";
    cout << "Player A: " << (domA != -1 ? "Strategy " + to_string(domA) : "None") << endl;
    cout << "Player B: " << (domB != -1 ? "Strategy " + to_string(domB) : "None") << endl;

    vector<pair<int, int>> nash = findNashEquilibria(matrix);
    cout << "\nNash Equilibria:\n";
    for (const auto& eq : nash)
        cout << "Player A: Strategy " << eq.first << ", Player B: Strategy " << eq.second << endl;

    return 0;
}
