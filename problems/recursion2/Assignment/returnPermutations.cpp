#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// int printPermutations(string input,string temp,string output[]){

//     	/* Don't write main() function.
// 	 * Don't read input, it is passed as function argument.
// 	 * Print output as specified in the question
// 	*/
//     int count =0;
//     if(input=="")
//     {
//     	output[0] = temp;	    
//         return count+1;
//     }
//     for(int i=0;i<input.size();i++)
//     {
//         count += printPermutations(input.substr(1),temp+input[0],output);
//         rotate(input.begin(),input.begin()+1,input.end());
//     }
    
//     return count;
// }

void change(char& a,char& b){
 	char temp = a;
    a= b;
    b= temp;
}

int fun(string input,string output[],int start_index){
    // cout<<input<<endl;
    // cout<<"startindex => "<<start_index<<endl;
    if(input.size() == 1){
        output[start_index] = input;
        return 1;
    }
    
    int i = 0;
    int num_perm = 0;
    int temp_num = 0;
    
    while(i<input.size()){
        change(input[0],input[i]);
        // cout<<input<<endl;

        temp_num = fun(input.substr(1),output,start_index);
        num_perm += temp_num;
        int j=start_index;
        while (j<temp_num+start_index)
        {
            /* code */
            output[j] = input[0] + output[j];
            j++;
        }
        

        start_index = temp_num+start_index;
        i++;
    }

    // cout<<num_perm<<endl;
    return num_perm;
}

// int permute(string input,int start,int end,string output[]){
    
// 	fun(input,output,)
    
//     return;
// }

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    int index = 0;
  	return fun(input,output,index);
    
    
}
   
int main(){
    string input = "abc"; 
    // cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

