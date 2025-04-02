#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    //pair declarations
    pair<int,int> p(10,20);
    pair<string,int> q = {"hello world",10};
    pair<char,double> r = make_pair('c',10.5);
    
    //pair element print
    cout<<p.first<<endl;
    cout<<p.second<<endl;
    cout<<q.first<<endl;
    cout<<q.second<<endl;
    cout<<r.first<<endl;
    cout<<r.second<<endl;

    pair<int,int> s(100,200);
    s.swap(p); //swap p & s elements, but they have to be the same data type
    cout<<"After swap"<<endl<<p.first<<endl;
    cout<<p.second<<endl;
    cout<<s.first<<endl;
    cout<<s.second<<endl;
}