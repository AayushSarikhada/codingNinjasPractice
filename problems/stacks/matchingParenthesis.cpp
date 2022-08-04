
//assume that expression contains only '(' and ')'
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isBalanced(string expression) 
{
    // Write your code here
   	stack<char> a;
    int flag = 0;
    for(int i=0;i<expression.size();i++){
        if(expression[i]==')' && a.empty()){
            flag = 1;
            break;
        }
        if(expression[i]==')' && !a.empty()){
            a.pop();
        }
        if(expression[i]=='('){
            a.push(expression[i]);
        }
    }
    if(!a.empty()){
        flag = 1;
    }
    if(flag){
        return false;
    }
    return true;
}

int main(){
    string temp = "()()()";
    cout<<isBalanced(temp)<<endl;

    return 0;
}