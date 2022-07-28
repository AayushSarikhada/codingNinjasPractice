while(temp2 != NULL){
                Node *temp4 = temp2;
                temp2 = temp2->next;
                delete temp4;
            }