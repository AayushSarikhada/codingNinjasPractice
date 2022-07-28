#include<iostream>
using namespace std;

void printSubSeq(string input,string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }

    printSubSeq(input.substr(1),output);
    printSubSeq(input.substr(1),output+input[0]);
}

int main(){
    string s;
    cin>>s;
    printSubSeq(s,"");
    return 0;
}