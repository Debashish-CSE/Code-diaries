#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    cout<<"Size: "<<v.size()<<endl;
    
    for(int i=0; i<10; i++) v.push_back(i);
    cout<<"Size now: "<<v.size()<<endl;
    cout<<"current contents: "<<endl;
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;

    for (int i=0; i<10; i++) v.push_back(i+10); //vector v er 10th position thke add hote thakbe (i+10) hishabe
    cout<<"Size now: "<<v.size()<<endl;
    cout<<"current contents: "<<endl;
    
    vector<int>::const_iterator i;
    for(i=v.begin(); i!=v.end(); i++) cout<<v[*i]<<" ";
    //for(i=0; i<v.size(); i++) cout<<v[*i]<<" ";
    cout<<endl;

    for (int i=0; i<10; i++) v.pop_back(); //vector er last theke 10 ta delete hoye jabe
     cout<<"Size now: "<<v.size()<<endl;
    cout<<"current contents: "<<endl;
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}