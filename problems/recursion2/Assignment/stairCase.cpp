#include <iostream>

using namespace std;

int staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(n==0){
        return 1;
    }
    if(n<0)
        return 0;
    
	int temp = 0;
    
    //method1 (better no extra recursive calls)
    if(n>=3){
        temp = staircase(n-1)+staircase(n-2)+staircase(n-3);
    }
    else if(n==2){
        temp = staircase(n-1)+staircase(n-2);
    }else{
        temp = staircase(n-1);
    }
    
    //method 2 (not good, gives extra calls)
    // temp = staircase(n-1)+staircase(n-2)+staircase(n-3);
    
    
    return temp;
    
    
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
