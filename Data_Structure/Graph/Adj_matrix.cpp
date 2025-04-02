#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, E;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> E;
    int Mat[N][N]; //create a 2D matrix
    memset(Mat, 0, sizeof(Mat)); // initialize matrix with 0
    
    cout << "Enter the node values: "<< endl;

    while (E--){
        int A, B;
        cin >> A >> B;
        Mat[A][B] = 1;
        Mat[B][A] = 1; //Undirected graph
    }

    //print the graph
    for(int i=0; i<N; i++){
        for(int j=0; j <N; j++){
            cout << Mat[i][j] << " ";
        }
        cout << endl;
    }

    if(Mat[2][1] == 1){
        cout << "2 and 1 are connected with an edge" <<endl;
    }
    else {
        cout << "2 and 1 are not conneccted with an edge" << endl;
    }

    return 0;
}