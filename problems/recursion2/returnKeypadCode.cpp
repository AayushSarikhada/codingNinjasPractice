#include <iostream>
#include <string>
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

int keypad(int number,string output[]){
    //base case
    if(number == 0){
        output[0] = "";
        return 1;
    }

    //recursive calls
    int smallNumber = number/10;
    int currentDigit = number%10;
    string currentString = getString(currentDigit);

    int smallOutputSize = keypad(smallNumber,output);
    string temp[smallOutputSize];
    for(int i=0;i<smallOutputSize;i++){
        temp[i] = output[i];
    }

    for(int i=0;i<currentString.size();i++){
        int start=i*smallOutputSize;
        for(int j=0;j<smallOutputSize;j++){
            output[start] = temp[j] + currentString[i];
            start++;
        }
    }

    return (smallOutputSize*currentString.size());

}

int main(){
    int num;
    cin >> num;

    string output[10000];
    
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
