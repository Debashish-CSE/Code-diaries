#include <iostream>
#include <map>

using namespace std;

int main(){
    map<char,int> m;
    m['j'] = 10;
    m['a'] = 1;
    m['k'] = 9;
    m['c'] = 3;
    map<char,int>::iterator i;
    for(i=m.begin(); i != m.end(); i++){
        cout<<i->first<<" "<<i->second<<endl;
    }

}