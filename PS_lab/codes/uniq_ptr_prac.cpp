#include <memory>
#include <iostream>
using uptr = std::unique_ptr<int>;
using namespace std;

int main()
{
    uptr ptr = make_unique<int>(6);
    uptr ptr2 = move(ptr); // Transfer ownership to ptr2

    cout << *ptr2 << endl; // Output: 6

    // No manual delete! unique_ptr will automatically delete when ptr2 goes out of scope.
    return 0;
}
