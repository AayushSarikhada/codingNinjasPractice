// input - input array
// size - length of input array
// element - value to be searched
#include <iostream>
using namespace std;

int solve(int input[],int start,int end,int element){
    if(start>end){
        return -1;
    }
    cout<<start<<" == "<<end<<endl;
	int size = end-start+1;
    int mid;
    
    if(size%2 == 0){
        mid = start+size/2-1;
    }else{
        mid = start +size/2;
    }
    
    if(element == input[mid]){
        return mid;
    }
    
    if(element < input[mid]){
    return solve(input,start,mid,element);    
    }else
    	return solve(input,mid,end,element);
    
    
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    return solve(input,0,size-1,element);
    
    
    
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}

