#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void swap(int& first,int& second){
    int temp = first;
    first = second;
    second = temp;
}

int partition(int input[],int start,int end){
    int pivot = input[start];
    int count=0;
    for(int i=start;i<=end;i++){
        if(pivot > input[i]){
            count++;
        }
    }
    int result_index = start+count;
    swap(input[start],input[result_index]);
    int i = start;
    int j = end;

    while(i<j){
        while(pivot > input[i]){
            i++;
        }
        while(pivot <= input[j]){
            j--;
        }
        if(i<j){
            // cout<<"i -> "<<i<<" "<<"j -> "<<j<<endl;
            swap(input[i],input[j]);
        }
    }
    
    return i;

}

void quickSort(int input[],int start,int end){
    if(start>=end)
        return;
    
    int pivot_index = partition(input,start,end);

    quickSort(input,start,pivot_index-1);
    quickSort(input,pivot_index+1,end);
}

int main(){

    int arr[] = {5,6,2,9,3,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<n<<endl;

    quickSort(arr,0,n-1);
    // cout<<partition(arr,0,n-1)<<endl;
    // cout<<endl;

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}

int main(){

    int arr[] = {5,6,2,9,3,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<n<<endl;

    quickSort(arr,0,n-1);

    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<endl;

    return 0;
}
