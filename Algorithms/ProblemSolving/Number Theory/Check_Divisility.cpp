#include<iostream>

using namespace std;
int main()
{
    cout<<"Value of a & b:";
    long long a,b;
    cin>>a>>b;
    long long q=a/b;
    long long reminder=a%b;
if (reminder==0)
{
    cout<<"YES"<<endl;
}else
{
    cout<<"NO"<<endl;
}


    return 0;
}