#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the value of n:";
    int n;
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        if (n%i==0)
        {
        cout<<i<<" ";
        }
        
    }
    cout<<endl;
    return 0;
}