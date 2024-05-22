#include <iostream>
#include <vector>

using namespace std;

int main(){
    //vector<int> v(5,1);  // v(size,content)=> ekhane 5 hocche vector er size and 5 ta 1 thakbe vector er content hishebe
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    cout<<"Size now: "<<v.size()<<endl;
    cout<<"original content of vector: "<<endl;
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;

    vector<int> t;
    t = v;
    for(int i=0; i<t.size(); i++) cout<<t[i]<<" ";
    cout<<endl;

    //insert into vector using iterator
    vector<int>::iterator i;
    i = v.begin()+2;      //iterator starts from the (0+2) = 3rd position of the vector
    v.insert(i, 10,0);    //from the position of the iterator i, 10 0s will be inserted in the vector
    cout<<"content of vector after insert: "<<endl;
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;

    i= v.begin()+5;      //iterator starts from 6th position
    v.insert(i, 5,9);    //from 6th position, 5 9s will be inserted into the vector
    cout<<"content of vector after 2nd insert: "<<endl;
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;

    //erase from vector using iterator
    i = v.begin()+4;     //iterator is in 5th position
    v.erase(i, i+10);    //erase element from iterator position, i=5th to (i+10)=14th position of the vector
    cout<<"content of vector after erase: "<<endl;
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;

}