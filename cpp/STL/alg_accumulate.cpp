#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.emplace_back(3);
    v.push_back(2);

    cout <<"v contains ";
    for (size_t s =0; s<v.size(); s++){
        cout<<v[s]<<" ";
    }
    cout<<endl;
    cout <<"The sum of the elements of v is "
         << accumulate(v.begin(), v.end(), 0) <<endl;
    cout <<"The inner product of v and itself is "
         << inner_product (v.begin(), v.end(), v.begin(), 0) << endl;

    return 0;

}