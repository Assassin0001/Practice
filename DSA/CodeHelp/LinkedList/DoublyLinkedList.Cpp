#include<iostream>
#include<map>

using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node* next;

    //constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }    

    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory freed for "<<val<<endl;
    }

};

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len; 

}

void insertAtHead(Node* &head,Node* &tail,int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }    
}

void insertAtTail(Node* &head,Node* &tail,int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    //First position
    if(position == 1){
        insertAtHead(head,tail,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    //Last position
    if(temp->next == NULL){
        insertAtTail(head,tail,d);
        return;
    }

    //Else positions
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    nodeToInsert->prev = temp;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* & head,Node* &tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp->next->prev = NULL;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        if(curr->next == NULL){
            tail = prev;
        }

        prev -> next = curr -> next;
        curr->prev = NULL;
        curr -> next  = NULL;
        delete curr;

    }
}

int main(){
    Node* head = NULL; 
    Node* tail = NULL;
    print(head);

    //cout<<getLength(head)<<endl;

    insertAtHead(head,tail,11);
    print(head);
    insertAtHead(head,tail,13);
    print(head);
    insertAtTail(tail,tail,8);
    print(head);
    insertAtPosition(head,tail,4,9);
    print(head);
    insertAtPosition(head,tail,2,12);
    print(head);

    deleteNode(1,head,tail);
    print(head);
    deleteNode(4,head,tail);
    print(head);
    
    return 0;
}