#include "../linkedlist1/linkedLIstOperations.cpp"

Node* oddEven(Node* head){
Node* odd = NULL;
    Node* even = NULL;
    Node* oddTemp = NULL;
    Node* evenTemp = NULL;
    Node* temp = head;
    
    if(temp == NULL){
        return head;
    }
    
    while(temp != NULL){
        if(temp->data%2 != 0){
            //if odd
            
            	if(odd == NULL) {
                    oddTemp = temp;
                    odd = oddTemp;
                
                }else{
                    oddTemp->next = temp;
                    oddTemp = oddTemp->next;
                }
        }else{
            
            	if(even == NULL) {
                    evenTemp = temp;
                    even = evenTemp;
                	
                }else{
                	evenTemp->next = temp;
                    evenTemp = evenTemp->next;
                }
        
        }
        temp = temp->next;
    }
     if(evenTemp != NULL)
    	evenTemp->next=NULL;
    
    if(oddTemp != NULL){
        oddTemp->next = even;
    }else{
        odd = even;
    }
   return odd;
}

int main(){
    Node* head = new Node(4);

    append(head,new Node(2));
    append(head,new Node(7));
    append(head,new Node(8));
    append(head,new Node(3));
    append(head,new Node(36));

    

    cout<<"before: "<<endl;
    print(head);
    cout<<"after: "<<endl;

    Node* temp = oddEven(head);

    print(temp);
    
    
    return 0;
}