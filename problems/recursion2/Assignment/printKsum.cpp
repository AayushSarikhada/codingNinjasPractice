#include<iostream>
#include<string>
using namespace std;


void helper(int input[],int size,string output,int k){
    
    if(size == 1){
    	if(input[0] == k){
            output = output+" "+to_string(input[0]);
            cout<<output<<endl;
        }
    }
    
    helper(input+1,size-1,output+" "+to_string(input[0]),k-input[0]);
    helper(input+1,size-1,output,k);
    
}


void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    helper(input,size,"",k);
    
}