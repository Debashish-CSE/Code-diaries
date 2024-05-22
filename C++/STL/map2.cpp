#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<char,int> m;
    for(int i=0; i<10; i++) m.insert(make_pair('a'+i, i));
    char ch;
    cout<< "Enter a key : "<<endl;
    cin>>ch;
    map<char,int>::iterator p;
    p = m.find(ch);
    if(p != m.end()){
        cout<<p->second<<endl;
        //cout<<p->first<<endl;
    }
    else{
        cout<<"Key does not exist"<<endl;
    }
    cout<<m['d']<<endl;
}