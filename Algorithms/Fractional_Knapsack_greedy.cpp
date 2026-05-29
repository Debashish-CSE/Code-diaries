#include <bits/stdc++.h>
using namespace std;

struct Item{ double value, weight; };

double fractionalKnapsack(vector<Item> a, double W){
    sort(a.begin(), a.end(), [](auto& x, auto& y){ return x.value/x.weight > y.value/y.weight; });
    double v=0;

    for(auto& it: a){
        if(W <= 0) break;
        if(it.weight <= W){ v += it.value; W -= it.weight; }
        else { v += it.value * (W/it.weight); W = 0; }
    }
    
    return v;
}

int main(){
    vector<Item> a={{60,10},{100,20},{120,30}};
    cout<<fixed<<setprecision(2)<<fractionalKnapsack(a,50)<<"\n";
}
