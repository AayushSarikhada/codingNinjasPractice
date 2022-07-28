#include<iostream>
using namespace std;

int main(){

    int* arr[5];

    for(int i=0;i<5;i++){
        arr[i] = new int[10];
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<10;j++){
            arr[i][j] = j;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    


}