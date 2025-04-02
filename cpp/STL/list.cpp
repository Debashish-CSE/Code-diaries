#include <iostream>
#include <list>

using namespace std;

int main(){
    //create a list
    list<int> numbers = {5,3,2};
    list<int> numbers2 = {7,9,8};

    //display the original list
    cout << "Initial List: ";
    for (int number: numbers){
        cout << number << " ";
    } 

    //add element at the beginning
    numbers.push_front(0);
    //add elements at the end
    numbers.push_back(4);

    //display the modified list
    cout<<endl;
    for (int number: numbers){
        cout << number << " ";
    }

    //numbers.reverse()
    //numbers.sort()
    //numbers.unique()
    //numbers.list2()
    numbers.merge(numbers2); // after merging, numbers list will have numbers+number2 elements, but numbers2 list will have 0 elements.
    cout<<endl;
    cout << "Final list: ";
    for (int number: numbers){
        cout << number << " ";
    }
    cout<<endl;
    return 0;

}