#include<iostream>
using namespace std;



int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    
    
	//base case:
    if(size == 0)
        return 0;
    
    //recursive call
    int ans = allIndexes(input+1,size-1,x,output);
    
    //small calculation
    
    //i) update each element of output array by 1 using iteratino from 0 to ans.
    // cout<<"ans : "<<ans<<endl;
    for(int i=0;i<ans;i++){
        // cout<<output[i]<<" ";
        output[i]++;
    }
    //ii)check at index 0 for match
    if(input[0] == x){
        //shift the output array elements to the right by one
        for(int i=ans;i>0;i--){
            
            output[i] = output[i-1];
        }
        output[0] = 0;
        
        ans++;
    }
    return ans;
    
        
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
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


