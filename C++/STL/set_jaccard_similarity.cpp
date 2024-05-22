#include <iostream>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string doc1 = "Data is the new oil of the digital economy";
    string doc2 = "Data is a new oil";
    stringstream S1(doc1);
    stringstream S2(doc2);
    string eachword1,eachword2;

    set<string> doclist1,temp1;
    while (S1 >> eachword1){        // each word is extracted from s1 stringstream until the stream ends, then insert each word to the set
        doclist1.insert(eachword1);
        temp1.insert(eachword1);
        cout << eachword1 << " ";
    }
    cout<< endl ;

    set<string> doclist2,temp2;
    while (S2 >> eachword2){
        doclist2.insert(eachword2);
        temp2.insert(eachword2);
        cout << eachword2 << " ";
    }
    cout<< endl;

    //union

    //doclist1.merge(doclist2); this also works, but it isn't supported in my C++ version
    set <string> common_set1;
    set_union(doclist1.begin(),doclist1.end(),
        doclist2.begin(),doclist2.end(),
        inserter(common_set1,begin(common_set1))
        );
        //doclist1.insert(doclist2.begin(),doclist2.end());
        cout<<"After union: ";
    for (string num: common_set1){
        cout << num << " ";
    }
    
    cout<<endl;

    //intersection

    set<string> common_set;

    set_intersection(
        temp1.begin(),temp1.end(),
        temp2.begin(),temp2.end(),
        inserter(common_set,common_set.begin())
        );
    cout<<"After intersection: ";
    for (string num: common_set){
        cout << num << " ";
    }
    cout<<endl;

    int a = common_set1.size();
    int b = common_set.size();
    cout << a << endl;
    cout << b << endl;
    double result = (double)b/a;
    cout << result << endl;
    return 0;
}
