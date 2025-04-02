#include <iostream>
#include <vector>

using namespace std;

int main(){
vector<int> v = {7,9,8};

v.push_back( 2 );
v.push_back( 3 );
v.push_back( 4 );

cout << "\nThe size of v is: "
     << v.size()
     << "\nThe capacity of v is: "
     << v.capacity()
     << '\n';

     /*for (int num : v){
        cout << num << ",";
     }*/
   
     cout <<"Content of v is \n";
     
     vector<int>::const_iterator i;

     for (i = v.begin(); i != v.end(); i++){
      cout << *i << '\n';
     }

     return 0;
}