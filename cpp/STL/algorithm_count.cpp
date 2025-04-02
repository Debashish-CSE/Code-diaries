#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v = {2,4,5,4,3,6,4,2,4,5,4,3,6,7,4,3,2,9,7,6,0,7,1};
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);

    int i;
    cout <<"Enter a number to find: ";
    cin >> i;
    cout << i <<" appears "<<count(v.begin(),v.end(),i) << " times in v"<<endl;

    return 0;
}