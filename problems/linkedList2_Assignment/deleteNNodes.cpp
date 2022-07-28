#include "../linkedlist1/linkedLIstOperations.cpp"

void deleteHere(Node* headaa){
    
    while(headaa!=NULL){
        cout<<headaa->data<<endl;
        Node* prev = headaa;
        headaa = headaa->next;
        delete prev;
        break;
    }

}

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(head == NULL){
        return head;
    }
    if(M == 0){
        deleteHere(head);
        return NULL;
    }
    if(N==0){
        return head;
    }
    
    int tempM = M;
    int tempN = N;
	Node* temp1 = head;
    
    while(temp1 != NULL && tempM > 1){
        temp1 = temp1->next;
        tempM--;
    }
    if(temp1==NULL) return head;
    
    Node* temp2 = temp1->next;
    cout<<temp2->data<<endl;
    while(temp2 != NULL && tempN > 1){
        temp2 = temp2->next;
        tempN--;
    }
    if(temp2 == NULL){
        deleteHere(temp1->next);
        return head;
    }
    Node* nextHead = temp2->next;
    temp2->next = NULL;
    
    deleteHere(temp1->next);
    
    temp1->next = skipMdeleteN(nextHead,M,N);
    
    return head;
    
}

int main(){

    Node* head = new Node(10);
    append(head,new Node(22));
    append(head,new Node(10));
    append(head,new Node(26));
    append(head,new Node(11));
    append(head,new Node(7));
    append(head,new Node(8));
    append(head,new Node(1));
    append(head,new Node(23));
    append(head,new Node(5));
    append(head,new Node(1));
    append(head,new Node(28));
    append(head,new Node(0));

    print(head);


    head = skipMdeleteN(head,2,3);
    print(head);
    return 0;
    
}