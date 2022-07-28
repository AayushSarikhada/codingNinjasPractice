#include <iostream>
using namespace std;

void updateValue(int *p){
    *p = 610%255;
    
}

int main(){
    char ch = 'A';
    char *pt = &ch;
    // updateValue((int*)pt);
    for(int i=0;i<10;i++){
        cout<<((void*)pt+i)<<" => "<<*(pt+i)<<endl;
    }
   
    




}
// #include<iostream>
// using namespace std;

// int main(){
//     int a = 65;
//     char c = a;
//     cout<<c<<endl;

//     int* p =&a;
//     char *cp = (char*) p; //explicit type casting
//     cout<<p<<endl;
//     cout<<*p<<endl;
//     cout<<cp<<endl;
   
//    for(int i=0;i<4;i++){
//     cout<<*(p+i)<<" "; //skipping 4 bytes with each i
//    }cout<<endl;

// for(int i=0;i<4;i++){
//     cout<<*(cp+i)<<" ";   //skipping 1 byte with each i
//    }cout<<endl;

// }

// note = 