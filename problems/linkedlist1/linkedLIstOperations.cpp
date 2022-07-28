#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int C = 0){
        data = C;
        next = NULL;
    }
};


Node* readInput(){
    Node* head = NULL;
    Node* tail = head;
    
    cout<<"enter number: (enter -1 if want to stop)"<<endl;
    while(true){
        int d;
        cin>>d;
        if(d == -1)
            break;
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = head;
            continue;
        }

        tail->next = newNode;
        tail = tail->next;


    }

    return head;
}

void print(Node* head){
    Node* temp = head;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<"end!"<<endl;
}

void append(Node* head,Node* node){
    Node* temp = head;
    if(head != NULL){
        while(temp->next != NULL){
            temp = temp->next;
        }
        
        temp->next = node;

    }

}
Node* insertAtFront(Node* head,Node* node){
    node->next = head;
    head = node;
    return head;
}

Node* deleteAt(Node* head,int pos){

    if(pos == 0){
        Node* temp = head->next;
        delete head;
        head=temp;
        return head;
    }
    Node* temp = head;
    while(temp->next !=NULL && pos > 1){
        temp = temp->next;
        pos--;
    }

    if(temp->next != NULL){
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;

    }
    return head;

}

Node* insertAt(Node* head,Node* node, int pos){
    Node* temp = head;

    if(pos == 0){
        head = insertAtFront(head,node);
    }
    else{
        while(temp->next!=NULL && pos > 1){
            temp = temp->next;
            pos--;
        }
        if(temp->next == NULL){
            temp->next = node;
        }else{
            Node* temp2 = temp->next;
            temp->next = node;
            node->next =temp2;

        }
    }

    return head;
}