#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string hello = "Hello";
    string world = "world!";
    string msg = hello + " " + world;
    cout << msg << endl;
    msg[0] = 'h';
    msg[6] = 'W';
    cout << msg << endl;
    

    //cout << "hello world\n" ;

    return 0;
}
