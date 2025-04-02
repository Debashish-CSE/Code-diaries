#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s = "asdf";
    cout << "original: "<<s<<endl;

    sort(s.begin(),s.end());
    cout<< "sorted: "<<s<<endl;

    string t(s);
    cout <<"permutation:"<<endl;
    int count = 0;
    do{
        next_permutation(s.begin(), s.end());
        cout<<s<<" ";
        count++;
    }
    while (s != t);
    cout <<endl<<"Total permutations: "<<count<<endl;
    
    return 0;







    
}