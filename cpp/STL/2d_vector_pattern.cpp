#include <iostream> 
#include <vector> 
using namespace std; 
int main() 
{ 
	int n = 4; 
	int m = 5; 

	/* 
	Create a vector containing "n" 
	vectors each of size "m". 
	*/
	vector<vector<int>> vec( n , vector<int> (m)); 

	for(int i = 0; i < n; i++) 
	{ 
		for(int j = 0; j < m; j++) 
		{ 
			vec[i][j] = j + i + 1; 
		} 
	} 

	for(int i = 0; i < n; i++) 
	{ 
		for(int j = 0; j < m; j++) 
		{ 
			cout << vec[i][j] << " "; 
		} 
		cout << endl; 
	} 
	
return 0; 
} 
