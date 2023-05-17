//Naive Approach
//T.C. O(n2) S.C. O(1)
class Solution
{
    public:
    Node *copyList(Node *head)
    {

        // step 1 :  Clone linked list
        Node* cloneHead = new Node(-1);
        Node* cloneTemp = cloneHead;
        
        Node* OriginalTemp = head;
        while(OriginalTemp){
            
            Node* newNode = new Node(OriginalTemp->data);
            cloneTemp->next = newNode;
            cloneTemp = newNode;
            
            OriginalTemp = OriginalTemp->next;
        }
        
        // step 2 :
        OriginalTemp = head;
        cloneTemp = cloneHead->next; 
        while(OriginalTemp){
            
            int cnt=0;
            
            Node* temp1 = head;
            while(temp1 != OriginalTemp->arb ){
                temp1 = temp1->next;
                cnt++;
            }
            
            Node* temp2 = cloneHead->next;
            while(cnt>0){
                temp2 = temp2->next;
                cnt--;
            }
            
            cloneTemp->arb = temp2;
            
            
            OriginalTemp = OriginalTemp->next;
            cloneTemp = cloneTemp->next;
        }
        return cloneHead->next;
        
    }

};


//Optimised Approach
//T.C. O(n) S.C. O(n)

class Solution
{
    public:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* temp = new Node(data);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        return;
    }
    
    Node *copyList(Node *head)
    {
        //Clone LL
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp = temp->next;
        }
        
        //Create a map
        unordered_map<Node*, Node*> oldToNewNode;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode && cloneNode){
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        //Arrange random Pointers
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode){
            cloneNode->arb = oldToNewNode[originalNode->arb];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;            
        }
        return cloneHead;
    }

};

//Optimised Approach
//Time Complexity -> O(N) Space Complexity -> O(1)

class Solution
{
    public:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* temp = new Node(data);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        return;
    }
    
    Node *copyList(Node *head)
    {
       //step1 : Create a clone list
       Node* cloneHead = NULL;
       Node* cloneTail = NULL;
       
       Node* temp = head;
       while(temp){
           insertAtTail(cloneHead,cloneTail,temp->data);
           temp = temp->next;
       }
       
       //step2 : cloneNodes add in between Original List
       Node* originalNode = head;
       Node* cloneNode = cloneHead;
       
       while(originalNode && cloneNode){
           Node* next = originalNode->next;
           originalNode->next = cloneNode;
           originalNode = next;
           
           next = cloneNode->next;
           cloneNode->next = originalNode;
           cloneNode = next;
       }
       
       //step3 : random pointer copy
       temp= head;
       while(temp){
           if(temp->next){
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
           } 
           temp = temp->next->next;
       } 
       
       //step4 : revert changes done in step2
       originalNode = head;
       cloneNode = cloneHead;
       while(originalNode && cloneNode){
           originalNode->next = cloneNode->next;
           originalNode = originalNode->next;
           
           if(originalNode) cloneNode->next = originalNode->next;
           cloneNode = cloneNode->next;
       }
       
       //step5 : return ans
       return cloneHead;
    }

};