#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, E;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> E;
    vector<int> Mat[N]; //create an array where each index are vectors
    
    cout << "Enter the node values: "<< endl;

    while (E--){
        int A, B;
        cin >> A >> B;
        Mat[A].push_back(B);
        Mat[B].push_back(A);  //Undirected
    }

    cout << "Elements that are connected with one " <<endl;
    for (int x : Mat[1]){
        cout << x << " ";
    }

    return 0;
}