#include <iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string doc1 = "Data is the new oil of the digital economy";
    string doc2 = "Data is a new oil";
    stringstream S1(doc1);
    stringstream S2(doc2);
    string eachword1,eachword2;

    list<string> doclist1,temp1;   
    while (S1 >> eachword1){        // each word is extracted from s1 stringstream until the stream ends, then push each word to the list
        doclist1.push_back(eachword1);
        temp1.push_back(eachword1);
        cout << eachword1 << " ";
    }
    cout<< endl ;

    list<string> doclist2,temp2;
    while (S2 >> eachword2){
        doclist2.push_back(eachword2);
        temp2.push_back(eachword2);
        cout << eachword2 << " ";
    }
    cout<< endl;

    //list copy

    /*list<string> temp1;
    for (string t: doclist1){
        temp1.push_back(t);
    }
    list<string> temp2;
    for (string t: doclist2){
        temp2.push_back(t);
    }
    int c = temp1.size();
    int d = temp2.size();
    cout<< c << endl;
    cout<< d << endl;*/
    
    //union
    doclist1.merge(doclist2);
    doclist1.sort();
    doclist1.unique();
    for (string num: doclist1){
        cout << num << " ";
    }
    cout<<endl;
    //intersection
  
    /*int count=0;
    for (string w1:temp1){
        for (string w2:temp2){
            if (w1 == w2) count++;
        }
    }*/

    list<string> common_list;
    temp1.sort();
    temp2.sort();
    
    set_intersection(
        temp1.begin(),temp1.end(),
        temp2.begin(),temp2.end(),
        back_inserter(common_list)
        );
    for (string num: common_list){
        cout << num << " ";
    }
    cout<<endl;

    int a = doclist1.size();
    int b = common_list.size();
    cout << a << endl;
    cout << b << endl;
    double result = (double)b/a;
    cout << result << endl;
    return 0;
}