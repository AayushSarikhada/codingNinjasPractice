#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//solution 1

// double geometricSum(int k) {
//     // Write your code here
//     if(k==0)
//         return 1;
    
//     return (1/pow(2,k) + geometricSum(k-1));

// }


//solution 2

double geometricSum(int k){
    if( k == 0 ){
        return 1;
    }

    return (1+(geometricSum(k-1)/2));
}


int main() {
    int k;
    cin >> k;
    
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
