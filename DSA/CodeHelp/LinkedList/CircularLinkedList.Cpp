#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
    cout<<"Memory Value freed for "<<value<<endl;        
    }

};

void insertNode(Node* &tail,int element,int d){
    //assuming element is present
    
    //empty List
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode; 
    }
    //Non Empty List
    else{
        Node* curr = tail;
        while(curr->data != element) curr=curr->next;
        //Element found

        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;

    }
    
}

void print(Node* &tail){
    Node* temp = tail;

    if(tail == NULL) cout<<"List is empty"<<endl;

    /*
    cout<<tail->data<<" ";
    while(tail->next != temp){
        cout<<tail->data<<" ";
        tail = tail->next;
    }*/

    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<endl;

}

void deleteNode(Node* &tail,int value){
    //empty List
    if(tail == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }

    //Non-empty List
    else{
        //Assuming value is present in linked list
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev=curr;
            curr=curr->next;
        }
        prev->next = curr->next;

        if(prev == curr) tail = NULL;
        //>= 2 Node
        if(tail == curr) tail = prev;
        curr->next = NULL;
        delete curr;

    }
}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}

int main(){
    Node* tail = NULL;

    //empty List Insertion
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    /*
    insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);
    
    insertNode(tail,3,4);
    print(tail);*/

    deleteNode(tail,3);
    print(tail);
    cout<<isCircularList(tail);
}

 