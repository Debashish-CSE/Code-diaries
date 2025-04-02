#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    for (int i=0; i<10; i++) v.push_back(i);
    cout<<"Content of v: "<<endl;
    vector<int>::iterator i; //iterator is a pointer
    for (i=v.begin(); i != v.end(); i++) cout<<v[*i]<<" ";
    cout<<endl;
}