#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int main(){
    string doc1 = "the best data science course";
    string doc2 = "data science is popular";
    vector<string> words1, words2;
    string eachword1,eachword2;
    stringstream S1(doc1),S2(doc2);
    
    while (S1 >> eachword1){
        words1.push_back(eachword1);
    }
    while (S2 >> eachword2){
        words2.push_back(eachword2);
    }
    
    set<string> vocab;
    for(int i=0; i<words1.size(); i++){
        vocab.insert(words1[i]);
    }
    for(int i=0; i<words2.size(); i++){
        vocab.insert(words2[i]);
    }
    cout<<"After union: ";
    for (auto i:vocab){
        cout<<i<<" ";
    }
    cout<<endl;
    /*set <string> vocab;
    set_union(words1.begin(),words1.end(),
        words2.begin(),words2.end(),
        inserter(vocab,begin(vocab))
        );
        //doclist1.insert(doclist2.begin(),doclist2.end());
        cout<<"After union: ";
    for (string st: vocab){
        cout << st << " ";
    }
    cout<<endl;*/

    vector<int> D1(vocab.size(),0), D2(vocab.size(),0);
    for (const string& w : words1) {
            auto it = find(vocab.begin(), vocab.end(), w);
            if (it != vocab.end()) {
                int index = distance(vocab.begin(), it);
                D1[index]++;
            }
        }
    cout<<"D1: ";
    for (int freq : D1) {
        cout << freq << " ";
    }
    cout << endl;

    for (const string& w : words2) {
            auto it = find(vocab.begin(), vocab.end(), w);
            if (it != vocab.end()) {
                int index = distance(vocab.begin(), it);
                D2[index]++;
            }
        }
    cout<<"D2: ";
    for (int freq : D2) {
        cout << freq << " ";
    }
    cout << endl;

    int dot_product = inner_product(D1.begin(), D1.end(), D2.begin(), 0);
    cout<<"Dot product: "<<dot_product<<endl;
    double magD1 = sqrt(inner_product(D1.begin(), D1.end(), D1.begin(), 0.0));
    double magD2 = sqrt(inner_product(D2.begin(), D2.end(), D2.begin(), 0.0));

    cout<<magD1<<" "<<magD2<<endl;

    double cosine_similarity = dot_product/(magD1*magD2);
    cout<<"Cosine similarity: "<<cosine_similarity<<endl;


}