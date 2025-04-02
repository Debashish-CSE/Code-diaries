#include <iostream>
#include <map>
using namespace std;
int main(){
    map<string, int> priceMap;
    priceMap.insert({"avocado",80});
    priceMap.insert(make_pair("Mango",70));
    priceMap["Melon"] = 90;

    for (auto st: priceMap){
        cout<< st.first << " " << st.second <<"\n";
    }

    map<string, int>::iterator i;
    for (i = priceMap.begin(); i!=priceMap.end(); i++){
        //cout<< "\t" << (*i).first << "\t" << (*i).second<<endl; //same
        cout<< "\t" << (i)->first << "\t" << (i)->second<<endl;
    }
    return 0;
}