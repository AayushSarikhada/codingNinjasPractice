#include <iostream>
using namespace std;

int sumOfDigits(int);

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}


int sumOfDigits(int n) {
    // Write your code here
    
    
    //base case
	if(n == 0)
        return 0;
    
    return (n%10 + sumOfDigits(n/10));
}