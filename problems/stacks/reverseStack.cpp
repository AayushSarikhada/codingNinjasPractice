#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
// 	stack<int> temp;
//     while(!input.empty()){
//         temp.push(input.top());
//         input.pop();
//     }
    
//     while(!temp.empty()){
//         extra.push(temp.top());
//         temp.pop();
//     }
    
//     while(!extra.empty()){
//         input.push(extra.top());
//         extra.pop();
//     }
    
    //base case
    if(input.size()<=1){
        return;
    }
    
    int last = input.top();
    input.pop();
    
    reverseStack(input,extra);
    
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    
    input.push(last);
    
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
        
    
}

int main(){

    int arr[] = {1,2,3,4,5,6};
    stack<int> st;
    for(int i=0;i<6;i++){
        st.push(arr[i]);
    }
    stack<int> an;
    reverseStack(st,an);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}