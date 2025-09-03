#include<iostream>

using namespace std;
int main()
{
    cout<<"Value of a & b:";
    long long a,b;
    cin>>a>>b;
    long long q=a/b;
    long long reminder=a%b;
    cout<<q<<" "<<reminder<<endl;
    return 0;
}