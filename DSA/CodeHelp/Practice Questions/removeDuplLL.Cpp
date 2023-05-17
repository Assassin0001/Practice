//Solution 
//Approach - I 
//T.C. O(N^2) , S.C. O(1)
Node * removeDuplicates( Node *head) 
{
    if(head == NULL || head->next == NULL) return head;
    Node* curr = head;
    while(curr){
        Node* temp = curr;
        while(temp && temp->next){
            if(curr->data == temp->next->data){
                Node* next_next = temp->next->next;
                delete temp->next;
                temp->next = next_next;
            }
            else temp = temp->next;
        }
        curr = curr->next;
    }
    return head;
}

//Approach II
//T.C. O(n) S.C. O(n)
Node *removeDuplicates(Node *head)
{
    if(head == NULL || head->next == NULL) return head;

    Node* curr = head;
    Node* prev = NULL;
    unordered_set<int> seen;
    while(curr){
        if(seen.find(curr->data) != seen.end()){
            prev->next = curr->next;
            delete curr;
        }
        else{
            seen.insert(curr->data);
            prev=curr;
        }
        curr=curr->next;
    }
    return head;
}    


