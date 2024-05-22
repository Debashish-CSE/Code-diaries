#include <iostream>
#include <set>

using namespace std;

int main(){
    //Ascending order (default set)
    set<char> a;
    a.insert('G');
    a.insert('F');
    a.insert('G');

    for (char st: a){
        cout << st << " ";
    }
    cout << "\n";
    return 0;
// FOR DESCENDING ORDER: set<char,greater<char>> a;
}