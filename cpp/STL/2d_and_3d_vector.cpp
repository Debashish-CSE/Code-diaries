#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> v2D = {
        {1,2},
        {4,5,6},
        {7,8,9,10}
    };
    
    vector<vector<vector<int>>> v3D;
    
    cout<<"2D vector: "<<endl;
    for(int i=0; i<v2D.size(); i++){
        for(int j= 0; j<v2D[i].size(); j++){
            cout<<v2D[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    /*vector<int> i= {1,2,3,4,5};
    v2d.push_back(i);
    for(int i=0; i<1; i++){
        for(int j= 0; j<5; j++){
            cout<<v2d[i][j]<<endl;
        }
        //cout<<endl;
    }*/

}