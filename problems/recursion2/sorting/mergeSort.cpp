#include<iostream>

void merge_sort(int ar[],int start,int end){
    if(start>=end){
        return;
    }
    
    int mid = (start+end)/2;
    merge_sort(ar,start,mid);
    merge_sort(ar,mid+1,end);

    int arr[end-start+1];
    int i=start;
    int j=mid+1;
    int k = 0;
    
    while(i<=mid && j<=end){
        if(ar[i]<ar[j]){
            arr[k] = ar[i];
            i++;
            k++;
        }
        else{
            arr[k] = ar[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        arr[k] = ar[i];
        i++;
        k++;
    }
    while(j<=end){
        arr[k] = ar[j];
        j++;
        k++;
    }
    // for(int l=start;l<=end;l++){
        
    //     std::cout<<ar[l]<<" ";
    // }
    // std::cout<<std::endl<<"---"<<std::endl;
    k=0;
    for( i=start;i<=end;i++){
        ar[i] = arr[k++];
        // std::cout<<ar[start]<<" ";
        
     }
    //  std::cout<<std::endl;
   
    
    
    
}

int main(){
    
    int ar[] = {10,9,8,7,6,5,4,3,2,1};
    int len = sizeof(ar)/sizeof(ar[0]);
    
    merge_sort(ar,0,len-1);
    for(int i=0;i<len;i++){
        std::cout<<ar[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}