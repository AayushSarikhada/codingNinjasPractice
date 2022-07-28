#include "../linkedlist1/linkedLIstOperations.cpp"


// class Node{
//     public:
//         int data;
//         Node* next;

//         Node(int d=0){
//             data = d;
//             next= NULL;
//         }
// };

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    
    Node* head = NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* temp = head;
    
    if(head1 ==NULL){
        return head2;
    }
    if(head2 == NULL)
        return head1;
    
    while(temp1 !=NULL && temp2 != NULL){
        // cout<<"temp1: "<<temp1->data<<endl;
        // cout<<"temp2: "<<temp2->data<<endl;

        // if(temp !=NULL){
            // cout<<"temp: "<<temp->data<<endl;   
            // cout<<"list til now: "<<endl;
            // print(temp);
            // cout<<endl;
        // }

    

        if(temp1->data < temp2->data){
            // cout<<"here1"<<endl;
            if(head ==NULL){
                head = temp1;
                temp = head;
            }
        	else{
                // cout<<"current temp: "<<endl;
                // print(temp);
                // cout<<"here1 before"<<endl;
                temp->next = temp1;
                // cout<<"here2 after"<<endl;
                temp = temp->next;
                // cout<<"here3 after"<<endl;

            }
        //    cout<<"here4 before"<<endl;
             temp1 = temp1->next;
        //    cout<<"here4 after"<<endl;
        }else{
            if(head == NULL){
                head = temp2;
                temp = head;
            }else{
                temp->next = temp2;
                temp = temp->next;
                
            }
            temp2 = temp2->next;
        }
         
    }

    // if(temp1 != NULL)
    //     cout<<"temp1aadfa: "<<temp1->data<<endl;
    // if(temp2 != NULL)
    //     cout<<"temp2affa: "<<temp2->data<<endl;
    // if(temp !=NULL){
    //         cout<<"tempdafad: "<<temp->data<<endl;
    //     }
    if(temp1 != NULL )
        temp->next = temp1;
    if(temp2 != NULL)
        temp->next = temp2;
    
    return head;
}

int main(){
    Node* head1 = readInput();
    Node* head2 = readInput();

    Node* newHead = mergeTwoSortedLinkedLists(head1,head2);

    print(newHead);
}