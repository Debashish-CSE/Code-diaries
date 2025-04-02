#include <iostream>
#include <list>

using namespace std;

int main(){
    //create a list
    list<string> list1 = {"Debashish","Chakraborty"};
    list<int> list2 = {7,9,8};
    
    //display the original list
    cout << "Initial List: ";
    for (string lists: list1){
        cout << lists << ",";
    } 
    //add element at the beginning
    list1.push_front("My name is");
     //add elements at the end
    list1.push_back("Prottoy");

    //display the modified list
    cout << endl , "Final List: ";
    for (string i: list1){
        cout << i << " ";
    }
    list1.sort();
    //numbers.sort()
    list1.unique(); // (Unique korar age sort korte hobe, karon sort korle pashapashi same element thakbe,
                    // erpor unique korle pashapashi same element er moddhe ekta delete hoye jabe.    
    //numbers.size()
    //numbers.merge(numbers2);
    cout<<endl;
    for (string i: list1){
        cout << i << " ";
    }
    cout<<endl;
    return 0;

}