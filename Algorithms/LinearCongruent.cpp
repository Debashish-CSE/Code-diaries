#include<iostream>
#include<string>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

bool iscongruent(long long a,long long b,long long m){
    
    if ((a-b)%m!=0)
    {
        return false;
    }
    return true;
}
int main()
{
    long long a,b,m;
    cin>>a>>b>>m;

    if (iscongruent(a,b,m))
    {
        cout<<a<<" is congruent to "<<b<<endl;
    }else
    {
        cout<<a<<" is not congruent to "<<b<<endl;
    }
    
    
    return 0;
}