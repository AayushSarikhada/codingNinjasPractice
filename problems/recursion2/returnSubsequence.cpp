#include<iostream>
using namespace std;


int subseq(string input,string output[]){
//base case   
    if(input.empty()){
        output[0]="";
        return 1;
    }
//recursive calls
string smallInput = input.substr(1);
int smallOutputSize = subseq(smallInput,output);

for(int i=0;i<smallOutputSize;i++){
    output[i+smallOutputSize] = input[0]+output[i];
}
return smallOutputSize*2;

}

int main(){
    string s;
    cin>>s;
    string* output = new string[1000];
    int n = subseq(s,output);



    for(int i=0;i<n;i++){
        cout<<output[i]<<endl;
    }
    cout<<endl;
    return 0;
}