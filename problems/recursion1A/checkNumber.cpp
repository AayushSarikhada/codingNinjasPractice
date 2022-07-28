#include<iostream>
using namespace std;


bool checkNumber(int input[], int size, int x) {
   /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	
    //base case
    if(size < 1)
        return -1;
    
    //check
    if(input[0] == x)
        return 0;
    
    //move on
    int flag = checkNumber(input+1,size-1,x);
    if(flag == -1)
        return -1;
    
    return(1+flag);
    


        
        

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}


