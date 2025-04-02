#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int largest_fact[t];
    
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        
        int max_prime = -1;
        
        // Removing all factors of 2
        while (n % 2 == 0) {
            max_prime = 2;
            n = n / 2;
        }
        
        // Finding odd prime factors
        for(int j = 3; j <= sqrt(n); j = j + 2){
            while (n % j == 0){
                max_prime = j;
                n = n / j;
            }
        }
        
        // Checking if the remaining number is a prime greater than 2
        if (n > 2 && n > max_prime){
            max_prime = n;
        }

        
        largest_fact[i] = max_prime;
    }

    for(int i = 0; i < t; i++){
        cout << largest_fact[i] << endl;
    }
}
