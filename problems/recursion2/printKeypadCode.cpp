#include<iostream>
using namespace std;


string getString(int digit){
    string temp;
    switch (digit)
    {
    case 2:
        temp = "abc";
        break;
    case 3:
        temp = "def";
        break;
    case 4:
        temp = "ghi";
        break;
    case 5:
        temp = "jkl";
        break;
    case 6:
        temp = "mno";
        break;
    case 7:
        temp = "pqrs";
        break;
    case 8:
        temp = "tuv";
        break;
    case 9:
        temp = "wxyz";
        break;
    default:
        break;
    }
    return temp;
}

void printKeyPadCode(int input,string output){

    //base case
    if(input == 0){
        cout<<output<<endl;
        return;
    }
    int nextNum = input/10;
    int currentDigit = input%10;
    string small = getString(currentDigit);
    for(int i=0;i<small.size();i++){
        printKeyPadCode(nextNum,output+small[i]);
    }
}

int main(){

    int input;
    cin>>input;
    printKeyPadCode(input,"");

    return 0;
}