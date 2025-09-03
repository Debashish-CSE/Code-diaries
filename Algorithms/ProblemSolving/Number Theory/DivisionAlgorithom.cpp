#include<iostream>

using namespace std;
int main()
{
    cout<<"Value of a & b:";
    long long a,b;
    cin>>a>>b;
    long long q=a/b;
    long long reminder=a%b;
    if (reminder<0)
    {
    q-=1;
    reminder+=b;
    }
    
    cout<<q<<" "<<reminder<<endl;
    return 0;
}