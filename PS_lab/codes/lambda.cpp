#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>  // for accumulate
using namespace std;

int main() {
    cout << "Basic Lambda\n";
    function<int(int)> square = [](int x) { return x * x; };
    cout << "Square of 5: " << square(5) << "\n";


    cout << "\nLambda Capture by Value [=]\n";
    int x = 10, y = 5;
    auto by_value = [=]() { cout << "x + y = " << x + y << "\n";};
    by_value();

    // int z = 9;
    
    // auto y = by_value();


    cout << "\nLambda Capture by Reference [&]\n";
    auto by_ref = [&]() { x++; y++; };
    by_ref();
    cout << "After by_ref(): x = " << x << ", y = " << y << "\n";


    cout << "\nMixed Capture [=, &y]\n";
    function<void(void)> mixed = [=, &y]() { y += 10; cout << "x = " << x << ", y = " << y << "\n"; };
    mixed();

    cout << "\nMutable Lambda\n";
    auto mutable_lam = [=]() mutable { x += 100; cout << "Inside lambda: x = " << x << "\n"; };
    mutable_lam();
    cout << "Outside lambda: x = " << x << "\n";


    cout << "\nLambda as Function Parameter\n";
    auto applyTo10 = [](function<void(int)> func) { func(10); };
    applyTo10([](int n) { cout << "10 * 2 = " << n * 2 << "\n"; });


    cout << "\n:sort with Lambda\n";
    vector<int> v = {4, 1, 7, 3};
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    for (int n : v) cout << n << " "; cout << "\n";


    cout << "\nfor_each\n";
    for_each(v.begin(), v.end(), [](int n) { cout << n << " squared = " << n * n << "\n"; });


    cout << "\ncount_if\n";
    int evens = count_if(v.begin(), v.end(), [](int n) { return n % 2 == 0; });
    cout << "Even numbers: " << evens << "\n";


    cout << "\ntransform\n";
    vector<int> squares;
    transform(v.begin(), v.end(), back_inserter(squares), [](int n) { return n * n; });
    for (int s : squares) cout << s << " "; cout << "\n";


    cout << "\nfind_if\n";
    auto it = find_if(v.begin(), v.end(), [](int n) { return n > 5; });
    if (it != v.end()) cout << "First >5: " << *it << "\n";


    cout << "\nLambda with State via Capture\n";
    int count = 0;
    auto counter = [&count]() { cout << ++count << "\n"; };
    counter(); counter(); counter();


    return 0;
}
