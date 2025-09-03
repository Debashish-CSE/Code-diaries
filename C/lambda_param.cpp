#include <iostream>
#include <functional>
using namespace std;

void brethe_taking(function<int(int)> func)
{
    int a = func(10); // Provide an argument
    cout << "The val: " << a << endl;
}

int main()
{
    function<int(int)> name = [](int a)
    {
        a++;
        return a;
    };

    brethe_taking(name);
    return 0;
}
