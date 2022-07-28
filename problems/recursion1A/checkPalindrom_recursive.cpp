#include <iostream>
using namespace std;
bool helper(char input[],int start,int end){
    //base case
    if(end == start){
        return true;
    }
    
    //small calculation
    if(input[start] == input[end]){
        if(start+1 <= end-1)
            return (helper(input,++start,--end));
        return true;
    }
    
    return false;
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int len = 0;
    int i=0;
    while(input[i] != '\0'){
        len++;
        i++;
    }

	return helper(input,0,len-1);
}




int main() {
    char input[50];
    cin >> input;
    
    // checkPalindrome(input);
    if(checkPalindrome(input)) {
        cout << "helo" << endl;
    }
    else {
        cout << "nalo" << endl;
    }
}

